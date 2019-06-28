#ifndef MODULES_IMGPROC_READIMG_H_
#define MODULES_IMGPROC_READIMG_H_
#include"types.h"
#define PNG_BYTES_TO_CHECK 4

namespace CVLab {
	void write_JPEG_file(const char * filename, Matrix64f & img, int quality);
	int read_JPEG_file(const char * filename, Matrix64f & img);
	int read_PNG_file(const char * filename, Matrix64f & img);
	void write_PNG_file(const char * filename, Matrix64f & img);
}

#endif //MODULES_IMGPROC_READIMG_H_

