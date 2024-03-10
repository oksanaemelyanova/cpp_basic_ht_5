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
    int A = 0;
    int B = 0;
    int C = 0;
    int a = 0;
    int b = 0;
    int c = 0;
  

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
      }
    }

  public:
    void getTriangleValues()
    {
      std::cout << "sides: " << A << ", " << B << ", " << C << std::endl;
      std::cout << "angles: " << a << ", " << b << ", " << c << std::endl;
      std::cout << std::endl;
    }
};

class SquareTriangle : public ChildTriangle
{
  public:
    SquareTriangle(int A, int B, int C, int a, int b, int c)
    {
      Some_form::name = "Square triangle";
      form_name();
      
      if (a != 90 && b != 90 && c != 90)
      {
        std::cout << "Error: angles must be 90" << std::endl;
        std::cout << std::endl;
      }
      else
      {        
        ChildTriangle::setTriangleValues(A, B, C, a, b, c);        
      }
      //ChildTriangle::getTriangleValues();
    }

  ~SquareTriangle() {}
  
};

class ChildRectangular : public Some_form
{
  private:
  int A;
  int B;
  int C;
  int D;
  int a;
  public:
    ChildRectangular(int A, int B, int C, int D, int angle)
    {
      Some_form::name = "Rectangular";
      setRectValues(A, B, C, D, angle);
      form_name();
    }
    void setRectValues(int A, int B, int C, int D, int angle)
    {
      if (A == C && B == D && angle == 90)
      {
      this->A = A;
      this->B = B;
      this->C = C;
      this->D = D;
      this->a = angle;
      }
    }
    void getRectValues()
    {  
      std::cout << "sides: " << A << ", " << B << ", " << C << ", " << D << std::endl;
      std::cout << "angles: " << a << ", " << a << ", " << a << ", " << a <<std::endl;
      std::cout << std::endl;
    }
};





void task2() {
  
  ChildTriangle chtr1(3, 4, 5, 55, 65, 30);
  chtr1.getTriangleValues();

  SquareTriangle sr1(3, 4, 5, 60, 80, 30);
  sr1.getTriangleValues();
  SquareTriangle sr2(3, 4, 5, 60, 90, 30);
  sr2.getTriangleValues();

  ChildRectangular chrect1(5, 3, 5, 3, 90);
  chrect1.getRectValues();


  return ; 
}