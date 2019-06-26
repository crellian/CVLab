#include <readimg.h>

GLOBAL(void) write_JPEG_file (const char * filename, Matrix & img, int quality)
{
    struct jpeg_compress_struct cinfo;  /* JPEG object */
    struct jpeg_error_mgr jerr;

    FILE* outfile;
    JSAMPROW row_pointer[1];  /* pointer to JSAMPLE row[s] */
    int row_stride = img.cols_ * 3;	/* JSAMPLEs per row in image_buffer */

    /* initialization */
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    /*set parameters*/
    cinfo.image_width = img.GetCol(); 	/* description of the input image */
    cinfo.image_height = img.GetRow();
    cinfo.input_components = img.GetChannel();
    cinfo.in_color_space = (img.GetChannel == 1) ? JCS_GRAYSCALE : JCS_RGB;

    jpeg_set_defaults(&cinfo); /* default parameters */

    jpeg_set_quality(&cinfo, quality, TRUE);

    /* destination file */
    if ((outfile = fopen(filename, "wb")) == NULL)
    {
        fprintf(stderr, "can't open %s\n", filename);
        exit(1);
    }
    jpeg_stdio_dest(&cinfo, outfile);

    /*start compressor*/
    jpeg_start_compress(&cinfo, TRUE);

    while (cinfo.next_scanline < cinfo.image_height)
    {
        row_pointer[0] = & img.ptr_[cinfo.next_scanline * row_stride];
        (void) jpeg_write_scanlines(&cinfo, row_pointer, 1); //more than one scanline could be passed at once
    }

    /*finish compression*/
    jpeg_finish_compress(&cinfo);

    fclose(outfile);
    jpeg_destroy_compress(&cinfo);
}


typedef struct my_error_mgr
{
    struct jpeg_error_mgr pub;

    jmp_buf setjmp_buffer;	/* for return to caller */
}* my_error_ptr;

/*
* replace the standard error_exit method
*/

METHODDEF(void)
my_error_exit(j_common_ptr cinfo)
{
    my_error_ptr myerr = (my_error_ptr)cinfo->err;

    (*cinfo->err->output_message) (cinfo);

    longjmp(myerr->setjmp_buffer, 1);           /*jump*/
}

GLOBAL(int) read_JPEG_file(const char * filename, Matrix & img)
{
    struct jpeg_decompress_struct cinfo;
    struct my_error_mgr jerr;

    FILE * infile;
    JSAMPARRAY buffer;
    int row_stride;


    if ((infile = fopen(filename, "rb")) == NULL)
    {
        fprintf(stderr, "can't open %s\n", filename);
        return 0;
    }


    cinfo.err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = my_error_exit;

    if (setjmp(jerr.setjmp_buffer))         /*jump to here*/
    {
        jpeg_destroy_decompress(&cinfo);
        fclose(infile);
        return 0;
    }

    jpeg_create_decompress(&cinfo);


    jpeg_stdio_src(&cinfo, infile);

    /*set parameters*/
    (void)jpeg_read_header(&cinfo, TRUE);
    img.create(cinfo.image_height, cinfo.image_width, 3);


    (void)jpeg_start_decompress(&cinfo);

    row_stride = cinfo.output_width * cinfo.output_components;

    buffer = (*cinfo.mem->alloc_sarray)
            ((j_common_ptr)&cinfo, JPOOL_IMAGE, row_stride, 1);


    while (cinfo.output_scanline < cinfo.output_height)
    {
        (void)jpeg_read_scanlines(&cinfo, buffer, 1);

        for (int i = 0; i < img.GetCol(); ++i)
        {
            img[cinfo.output_scanline - 1][i * 3 + 2] = buffer[0][i * 3 + 0];
            img[cinfo.output_scanline - 1][i * 3 + 1] = buffer[0][i * 3 + 1];
            img[cinfo.output_scanline - 1][i * 3 + 0] = buffer[0][i * 3 + 2];
        }
    }

    (void)jpeg_finish_decompress(&cinfo);

    jpeg_destroy_decompress(&cinfo);
    fclose(infile);

    return 1;
}

#ifndef png_jmpbuf
#  define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf)
#endif

int read_PNG_file(const char * filename, Matrix & img)
{
    png_structp png_ptr;
    png_infop info_ptr;
    char buf[PNG_BYTES_TO_CHECK];
    FILE* infile;

    if ((infile = fopen(filename, "rb")) == NULL)
    {
        return (ERROR);
    }

    if (fread(buf, 1, PNG_BYTES_TO_CHECK, infile) != PNG_BYTES_TO_CHECK)
    {
        fclose(infile);
        return (ERROR);
    }

    if (png_sig_cmp(buf, (png_size_t)0, PNG_BYTES_TO_CHECK))
    {
        fclose(infile);
        return (ERROR);
    }

    /*
    * Create and initialize the png_struct with the desired error handler functions.
    */

    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr)
    {
       fclose(infile);
       return (ERROR);
    }

    /* Allocate/initialize the memory for image information*/
    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
       fclose(infile);
       png_destroy_read_struct(&png_ptr, NULL, NULL);
       return (ERROR);
    }

    /*
    * Set error handling
    */

    if (setjmp(png_jmpbuf(png_ptr)))
    {
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       fclose(infile);
       return (ERROR);
    }

    /*
    * Set up the input control
    */
    png_init_io(png_ptr, infile);

    png_set_sig_bytes(png_ptr, PNG_BYTES_TO_CHECK); /* already read some of the signature */

    /*start reading*/
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_BGR, NULL);
    img.create(static_cast<int>(info_ptr->height), static_cast<int>(info_ptr->width), info_ptr->channels);
    auto row_pointers = png_get_rows(png_ptr, info_ptr);

    for(auto i = 0; i < info_ptr->height; ++i)
    {
        memcpy(img.ptr_ + img.step_ * i, row_pointers[i], static_cast<size_t>(img.step_));
    }

    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    fclose(fp);

    return (OK);
}

void write_PNG_file(const char * filename, Matrix & img)
{
    png_structp png_ptr;
    png_infop info_ptr;
    FILE* outfile;

    if ((outfile = fopen(filename, "wb")) == NULL)
    {
        return (ERROR);
    }

    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png_ptr == NULL)
    {
       fclose(outfile);
       return (ERROR);
    }

    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL)
    {
       fclose(outfile);
       png_destroy_write_struct(&png_ptr, NULL);
       return (ERROR);
    }

    if (setjmp(png_jmpbuf(png_ptr)))
    {
       fclose(outfile);
       png_destroy_write_struct(&png_ptr, &info_ptr);
       return (ERROR);
    }

    png_init_io(png_ptr, fp);

    png_write_png(png_ptr, info_ptr, png_transforms, png_voidp_NULL);

    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);

    return (OK);
}





