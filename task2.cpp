#include "hw5.hpp"

class Some_form
{
  protected:
    std::string name = "Form";

  public:
    Some_form() {}
    void form_name()
    {
      std::cout << name << ": " << std::endl;
    }
};

class ChildTriangle : public Some_form
{
  private:
    //angles
    int A = 0;
    int B = 0;
    int C = 0;
    //sides
    int a = 0;
    int b = 0;
    int c = 0;
  
    int goodOne = 0;

  public:
    ChildTriangle() {};
    ChildTriangle(int A, int B, int C, int a, int b, int c)
    { 
      Some_form::name = "Triangle";
      form_name();
      setTriangleValues(A, B, C, a, b, c);      
    }

  protected:
    void setTriangleValues(int A, int B, int C, int a, int b, int c)
    {
      if (A > 0 && B > 0 && C > 0 && a > 0 && b > 0 && c > 0)
      {
        this->A = A;
        this->B = B;
        this->C = C;
        this->a = a;
        this->b = b;
        this->c = c;
        this->goodOne = 1;
      }
    }

  public:
    void getTriangleValues()
    {
      if (goodOne == 1) {
        std::cout << "sides: " << a << ", " << b << ", " << c << std::endl;
        std::cout << "angles: " << A << ", " << B << ", " << C << std::endl;
        std::cout << std::endl;
      }
      else {
        std::cout << "sorry the form isn't initialized yet" << std::endl;
      }
      
    }
};

class SquareTriangle : public ChildTriangle
{
  public:
    SquareTriangle(int A, int B, int a, int b, int c)
    {
      Some_form::name = "Square triangle";
      form_name();
      
      ChildTriangle::setTriangleValues(A, B, 90, a, b, c);
    }

  ~SquareTriangle() {}  
};

class isoscelesTriangle : public ChildTriangle
{
  public:
    isoscelesTriangle(int A, int B, int C, int a, int b, int c)
    {
      Some_form::name = "Isosceles triangle";
      form_name();
      
      if (a != c || A != C)
      {
        std::cout << "Error: side a should be equal to side c and same for angles" << std::endl;
        std::cout << std::endl;
      }
      else
      {        
        ChildTriangle::setTriangleValues(A, B, C, a, b, c);        
      }
      
    }

  ~isoscelesTriangle() {}  
};


class equilateralTriangle : public ChildTriangle
{
  public:
    equilateralTriangle(int side)
    {
      Some_form::name = "Equilateral triangle";
      form_name();
     
      ChildTriangle::setTriangleValues(60, 60, 60, side, side, side);      
    }

  ~equilateralTriangle() {}  
};


class ChildRectangular : public Some_form
{
  private:
  //sides
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int angle = 0;
  int goodOne = 0;
  public:
    ChildRectangular () {};
    ChildRectangular(int a, int b, int c, int d, int angle)
    {
      Some_form::name = "Rectangular";
      setRectValues(a, b, c, d, angle);
      form_name();
    }
    void setRectValues(int a, int b, int c, int d, int angle)
    {
      if (a == c && b == d && angle == 90)
      {
      this->a = a;
      this->b = b;
      this->c = c;
      this->d = d;
      this->angle = angle;
      this->goodOne = 1;
      }
      else {
        std::cout << "please check sides and the angle" << std::endl;
      }
    }
    void getRectValues()
    {
      if (goodOne == 1) {
        std::cout << "sides: " << a << ", " << b << ", " << c << ", " << d << std::endl;
        std::cout << "angle: " << angle <<std::endl;
        std::cout << std::endl;
      }  
      else {
        std::cout << "sorry, the form isn't initialized yet" << std::endl;
      }
    }
};

class square : public ChildRectangular
{
  public:
    square(int side) 
    {
      Some_form::name = "square";
      form_name();
         
      ChildRectangular::setRectValues(side, side, side, side, angle);   
    }

  ~square() {}  
};



void task2() {

  std::cout << "------triangle tests------ " << std::endl;
  std::cout << "wrong one: " << std::endl;  
  ChildTriangle chtr1(55, 65, -30, 3, 5, 6);
  chtr1.getTriangleValues();
  std:: cout << "correct one: " << std::endl;
  ChildTriangle chtr2(55, 65, 30, 3, 5, 6);
  chtr2.getTriangleValues();

  std::cout << std::endl << "----------square triangle tests--------- " << std::endl;
 
  SquareTriangle sr2(60, 20, 4, 4, 5);
  sr2.getTriangleValues();

  std::cout << "-------isosceles triangles tests------" << std::endl;
  std::cout << "wrong one: " << std::endl;
  isoscelesTriangle isoT2(60, 80, 50, 14, 4, 14);
  isoT2.getTriangleValues();
  std:: cout << "correct one: " << std::endl;
  isoscelesTriangle isoT1(50, 80, 50, 14, 4, 14);
  isoT1.getTriangleValues();

  std::cout << "-------equilateral triangles tests------" << std::endl;
  equilateralTriangle eqT2(767);
  eqT2.getTriangleValues();
 
  
  
  std::cout << "-------rectangular tests------" << std::endl;
  std:: cout << "correct one: " << std::endl;
  ChildRectangular chrect1(5, 3, 5, 3, 90);
  chrect1.getRectValues();
  std::cout << "wrong ones: " << std::endl;
  ChildRectangular chrect2(5, 3, 15, 3, 90);
  chrect2.getRectValues();
  ChildRectangular chrect3(5, 3, 5, 3, 60);
  chrect3.getRectValues();

  return ; 
}