#include "hw5.hpp"

class Figure {
protected:
    std::string name = "Figure";
    int sides_count = 0;

public:
    Figure() {}
    virtual ~Figure() {}

    virtual void printInfo() const {
        std::cout << name << std::endl;
        std::cout << "Number of sides: " << sides_count << std::endl;
    }
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {
        name = "Triangle";
        sides_count = 3;
    }

    void printInfo() const override {
        Figure::printInfo();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
    ~Triangle() {};
};

class SquareTriangle : public Triangle {
public:
    SquareTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Square Triangle";
    }
    ~SquareTriangle() {};
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C)
        : Triangle(a, b, c, A, B, C) {
        name = "Isosceles Triangle";
    }

    ~IsoscelesTriangle() {};
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Equilateral Triangle";
    }

    ~EquilateralTriangle(){};
};

class Quadrilateral : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrilateral(){};
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
        name = "Quadrilateral";
        sides_count = 4;
    }

    void printInfo() const override {
        Figure::printInfo();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
    ~Quadrilateral(){};
};

class Parallelogram : public Quadrilateral
{
  public:
    Parallelogram () {};
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) 
    : Quadrilateral(a, b, c, d, A, B, C, D) {
      name = "Parallelogram";    
    }
  
    ~Parallelogram() {};  
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b)
        : Parallelogram(a, b, a, b, 90, 90, 90, 90) {
        name = "Rectangle";
    }

    ~Rectangle();
};

class Square : public Parallelogram {
public:
    Square(int side)
        : Parallelogram(side, side, side, side, 90, 90, 90, 90) {
        name = "Square";
    }

    ~Square() {};
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int A, int B)
        : Parallelogram(side, side, side, side, A, B, A, B) {
        name = "Rhombus";
    }

    ~Rhombus() {};
};

void task2() {
  
    Figure* ff = new Figure();
    ff->printInfo();
    

    std::cout << "------triangle tests------ " << std::endl;
    Figure* tr1 = new Triangle (10, 20, 30, 50, 60, 70);
    Figure* tr2 = new Triangle (10, 20, 30, 150, 60, 70);
    tr1->printInfo();
    tr2->printInfo();
    Figure* st1 = new SquareTriangle(10, 20, 30, 60, 30);
    st1->printInfo();
    Figure* it1 = new IsoscelesTriangle(2, 5, 2, 50, 80, 50);
    Figure* it2 = new IsoscelesTriangle(2, 5, 2, 55, 75, 50);
    it1->printInfo();
    it2->printInfo();
    Figure* et1 = new EquilateralTriangle(77);
    et1->printInfo();

    std::cout << "------Quadrilateral tests------ " << std::endl;
    Figure *QQ = new Quadrilateral(23, 12, 34, 4, 90, 90, 100, 80);
    QQ->printInfo();
    Figure *QQ1 = new Quadrilateral(23, 12, 34, 4, 90, 190, 100, 80);
    QQ1->printInfo();
    Figure *pr1 = new Parallelogram(43, 90, 43, 90, 10, 170, 10, 170);
    pr1->printInfo();
    Figure *pr2 = new Parallelogram(43, 90, 43, 90, 10, 160, 10, 170);
    pr2->printInfo();
    Figure* sq = new Square(89);
    sq->printInfo();
    Figure *rr = new Rhombus(56, 100, 80);
    rr->printInfo();

    delete ff, tr1, tr2, st1;
    delete it1, it2, et1;
    delete QQ, QQ1, pr1, pr2, sq, rr;

    return ;
}

