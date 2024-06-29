#include <iostream>
using namespace std;
class Calculator
{
public:
    virtual void add() = 0;
    virtual void subtract() = 0;
    virtual void multiply() = 0;
    virtual void divide() = 0;
};

class SimpleNumber : public Calculator
{
private:
    int a;
    int b;

public:
    SimpleNumber(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void add()
    {
        cout << "Addition: " << a + b << endl;
    }

    void subtract()
    {
        cout << "Subtraction: " << a - b << endl;
    }

    void multiply()
    {
        cout << "Multiplication: " << a * b << endl;
    }

    void divide()
    {
        if (b != 0)
        {
            cout << "Division: " << a / b << endl;
        }
        else
        {
            cout << "Cannot divide by zero." << endl;
        }
    }
};
class ComplexNum
{
private:
    int real;
    int img;

public:
    ComplexNum()
    {
        img = real = 0;
    }
    ComplexNum(int real, int img)
    {
        this->real = real;
        this->img = img;
    }
    void add(ComplexNum temp)
    {
        cout << "Addition: " << real + temp.real << " + " << img + temp.img << "i" << endl;
    }

    void subtract(ComplexNum temp)
    {
        cout << "Subtraction: " << real - temp.real << " - " << img - temp.img << "i" << endl;
    }

    void multiply(ComplexNum temp)
    {
        cout << "Multiplication: " << (real * temp.real) + (real * temp.img) << " * " << (img * temp.real) + (img * temp.img) << "i" << endl;
    }

    void divide(ComplexNum temp)
    {
        if (img != 0)
        {
            cout << "Division: " << (((real * temp.real) + (img + temp.img)) / (temp.real * temp.real) + (temp.img * temp.img)) + (((img * temp.real) - (real * temp.img)) / (temp.real * temp.real) + (temp.img * temp.img)) << endl;
        }
        else {
            cout << "Cannot divide by zero." << endl;
        }
    }
};
class ComplexNumber : public Calculator
{
private:
    ComplexNum a;
    ComplexNum b;
public:
    ComplexNumber(ComplexNum c1, ComplexNum c2)
    {
        a = c1;
        b = c2;
    }
    void add()
    {
        a.add(b);
    }
    void subtract()
    {
        a.subtract(b);
    }
    void multiply()
    {
        a.multiply(b);
    }
    void divide()
    {
        a.divide(b);
    }
};



int main()
{
    cout << "Enter 1 to create a SimpleNumber object or 2 to create a ComplexNum object: ";
    int input;
    cin >> input;

    Calculator* c1 = 0;

    if (input == 1)
    {
        int a, b;
        cout << "Enter two integers: ";
        cin >> a >> b;
        c1 = new SimpleNumber(a, b);
        c1->add();
        c1->subtract();
        c1->multiply();
        c1->divide();

    }
    else if (input == 2)
    {
        int r1, i1, r2, i2;
        cout << "Enter r1: ";
        cin >> r1;
        cout << "Enter i1: ";
        cin >> i1;
        cout << "Enter r2: ";
        cin >> r2;
        cout << "Enter i2: ";
        cin >> i2;
        ComplexNum a(r1, i1);
        ComplexNum b(r2, i2);
        c1 = new ComplexNumber(a, b);
        c1->add();
        c1->subtract();
        c1->multiply();
        c1->divide();

    }
    else
    {
        cout << "Invalid choice." << endl;
    }
    if (c1)
    {
        delete c1;
    }
   

    return 0;
}