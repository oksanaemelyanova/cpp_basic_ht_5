#include "hw1.hpp"

class Some_form
{
  protected:
    std::string name = "Form";
    int sides = 0;

  public:
    Some_form() {}
    void how_many_sides()
    {
      std::cout << name << ": " << sides << std::endl;
    }
};

class ChildTriangle : public Some_form
{
  public:
    ChildTriangle()
    {
      Some_form::name = "Triangle";
      Some_form::sides = 3;
    }
};

class ChildRectangular : public Some_form
{
  public:
    ChildRectangular()
    {
      Some_form::name = "Rectangular";
      Some_form::sides = 4;
    }
};

void task1() {
  Some_form f1;
  f1.how_many_sides();

  ChildTriangle chtr1;
  chtr1.how_many_sides();

  ChildRectangular chrect1;
  chrect1.how_many_sides();

  return ; 
}