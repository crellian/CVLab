# CVLab

## namespace CVlab


##
Vector Class:
Vector (int8_t),Vector8u,Vector8s,Vector16u,Vector16s,Vector32f,Vector64d
Create a Vector:
1. Vector v;
2. Vector v(10);            //10 elements
3. Vector v(10, 2.0);       //each element is 2.0
4. Vector v(10, array);     //convert an array to vector
5. Vector v2(v1);

Assignment:
1. v = {1, 2, 3};
2. v1 = v2;                 //deep copy

Access:
1. v[1] = 2;
   v[1] = v[2];
2. len = v.GetLen;
3. v.SetLen(len);

Comparison:
1. v1 == v2;
2. v1 != V2;

Output:
cout << v;


##
Size Class:
Size (int),Sizei,Sized,Sizef
Create a Size:
1. Size s;
2. Size s(1, 1);              //width, height
3. Size s2(s1);

Access:
1. w = s.GetWidth();
   h = s.GetHeight();
2. s.SetWidth(1);
   s.SetHeight(1);
3. area = s.area();

Comparison:
1. s1 == s2
2. s1 != s2

Output:
cout << s;


##
Complex Class:
Complex (int8_t),Complex8u,Complex16s,Complex16u,Complex32s,Complex32u,Complex32f,Complex64d
Methods are derived from std::complex class


##
Point3 Class (3D Point):
Point3 (int),Point3i,Point3d,Point3f
Create a 3D Point:
1. Point3 p;
2. Point3 p(1,1,1);          //x, y, z         
3. Point3 p2(p1);

Access:
1. p.SetX(1);
   p.SetY(1);
   p.SetZ(1);
2. x = p.GetX();
   y = p.GetY();
   z = p.GetZ();

Comparison:
1. p1 == p2
2. p1 != p2
3. p1 <= p2
4. p1 < p2
5. p1 >= p2
6. p1 > p2

Output:
cout << p;

Arithmetic:
1. p1 + p2
2. p1.DotPdt(p2);
3. p1.CrossPdt(p2);


##
Point Class (2D Point):
Point (int),Pointi,Pointd,Pointf
Create a 2D Point:
1. Point p;
2. Point p(1,1);              //x, y
3. Point p2(p1);

Access:
1. p.SetX(1);
   p.SetY(1);
2. x = p.GetX();
   y = p.GetY();

Comparison:
1. p1 == p2
2. p1 != p2
3. p1 <= p2
4. p1 < p2
5. p1 >= p2
6. p1 > p2

Output:
cout << p;

Arithmetic:
1. p1 + p2
2. p1.DotPdt(p2);
3. p1.CrossPdt(p2);


##
Rect Class (Rectangle):
Rect (int),Rect_int,Rect_float,Rect_double
Create a Rectangle:
1. Rect r;
2. Rect r(1,1);              //width,height,positionX=0,positionY=0
3. Rect r(1,1,1,1);          //width,height,positionX,positionY
4. Rect r(s,p);              //Size(width,height), 2D Point(positionX,positionY)
5. Rect r(p1,p2);            //2D Point(width,height), 2D Point(positionX,positionY)

Access:
1. r.GetTL();
   r.GetBR();
2. r.GetSize();
3. r.SetWidth(1);
   r.SetHeight(1);
   r.SetX(1);
   r.SetY(1);
4. r.GetWidth();
   r.GetHeight();
   r.GetX();
   r.GetY();
5. r.contain(p);             //Whether a Point lies inside the rectangle


##
Scalar Class:
Scalar (double),Scalar64f,Scalar32f,Scalar32u,Scalar32s,Scalar8u,Scalar8s
Create a Scalar:
1. Scalar s;
2. Scalar s(1);              //v1, v2=0, v3=0, v4=0
2. Scalar s(1,1,1,1);        //v1, v2, v3, v4
3. Scalar s2(s1);

Assignment:
1. s.init(1);                //v1=v2=v3=v4=1
2. s2 = s1.conj();           //v1, -v2, -v3, -v4

Access:
v[3]                         //v4

Comparison:
1. s1 == s2
2. s1 != s2

Trait:
s.isReal()                   //return true if v2=v3=v4=0

Arithmetic:
1. v1 += v2
2. v1 -= v2
3. v1 *= 2
4. v1 + v2
5. v1 - v2
6. v1 * 2, 2 * v1

Output:
cout << s;

##
Matrix Class
Matrix (double),Matrix64f,Matrix32f,Matrix32s,Matrix32u,Matrix16s,Matrix16u
Create a matrix:
1. Matrix m;
2. Matrix m(2, 2);            //row, col, channel = 1
3. Matrix m(2, 2, 1);         //row, col, channel
4. Matrix m(s);               //Size, channel = 1
5. Matrix m(s, 1);            //Size, channel
6. Matrix m2(m1);

Assignment:
1. m = {1, 2, 3};
2. m1 = m2;                   //deep copy

Creation and Assignment
1. Matrix::eye(3);
2. Matrix::zeros(2, 2, 1);    //row, col, channel = 1
3. Matrix::ones(2, 2, 1);     //row, col, channel = 1
4. Matrix::eye(2,4);

Access:
1. m[1][2]
2. m.GetRow()
   m.GetCol()
   m.GetChannel()
3. m.GetSize()

Trait:
1. m.isempty()
2. m.trace()
3. m.rank()

Comparison:
1. m1 == m2
2. m1 != m2

Arithmetic:
1. m.transpose()
2. m.dot(m1)
3. m.inv()
4. conv(m1, m2)                //mat, core, normalize = true, ccorr = true
5. conv(m1, m2, true, true)
6. m1 * m2
   m1 * 2
   2 * m1
7. m1 + m2
   m1 + 2
   2 + m1
8. m1 - m2
   m1 - 2
   2 - m1

Output:
cout << m;

Other:
m.recreate()                   //For reference counting