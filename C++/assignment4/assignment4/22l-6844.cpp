//#include<iostream>
//#include<cmath>
//using namespace std;
//class ComplexNumber
//{
//private:
//	int* real;
//	int* imaginary;
//public:
//	ComplexNumber(int r = 0, int i = 0)
//	{
//		real = new int(r);
//		imaginary = new int(i);
//	}
//	ComplexNumber(const ComplexNumber& c)
//	{
//		real = new int(*c.real);
//		imaginary = new int(*c.imaginary);
//	}
//	ComplexNumber& operator=(const ComplexNumber& c)
//	{
//		if (&c != this)
//		{
//			*real = *c.real;
//			*imaginary = *c.imaginary;
//		}
//		return *this;
//	}
//	void Input()
//	{
//		cout << "Enter the real part: ";
//		cin >> *real;
//		cout << "Enter the imaginary part: ";
//		cin >> *imaginary;
//	}
//	void Output()
//	{
//		if (*imaginary >= 0)
//		{
//			cout << *real << "+" << *imaginary << "i" << endl;
//		}
//		else
//		{
//			cout << *real << *imaginary << "i" << endl;
//		}
//	}
//	bool IsEqual(ComplexNumber c)
//	{
//		if (*real == *c.real && *imaginary == *c.imaginary)
//		{
//			return true;
//		}
//		return false;
//	}
//	ComplexNumber Conjugate()
//	{
//		ComplexNumber con;
//		*(con.real) = *real;
//		*(con.imaginary) = -*imaginary;
//		return con;
//	}
//	ComplexNumber Add(ComplexNumber c)
//	{
//		ComplexNumber sum;
//		*(sum.real) = *real + *c.real;
//		*(sum.imaginary) = *imaginary + *c.imaginary;
//		return sum;
//	}
//	ComplexNumber Subtract(ComplexNumber c)
//	{
//		ComplexNumber res;
//		*(res.real) = *real - *c.real;
//		*(res.imaginary) = *imaginary - *c.imaginary;
//		return res;
//	}
//	ComplexNumber Multiply(ComplexNumber c)
//	{
//		ComplexNumber res;
//		*(res.real) = *real * *c.real - *imaginary * *c.imaginary;
//		*(res.imaginary) = *real * *c.imaginary + *c.real * *imaginary;
//		return res;
//	}
//	float Magnitude()
//	{
//		float res = *real * *real + *imaginary * *imaginary;
//		res = sqrt(res);
//		return res;
//	}
//	~ComplexNumber()
//	{
//		delete[] real;
//		delete[] imaginary;
//	}
//};
//
//void main()
//{
//	float a, b;
//	ComplexNumber c1, c2, conjugate1, conjugate2, sum, sub, mul;
//	cout << "Enter c1: \n";
//	c1.Input();
//	cout << "Enter c2: \n";
//	c2.Input();
//	cout << "c1:  ";
//	c1.Output();
//	cout << "c2:  ";
//	c2.Output();
//	if (c1.IsEqual(c2))
//	{
//		cout << "c1 is Equal to c2\n";
//	}
//	else
//	{
//		cout << "c1 is NOT Equal to c2\n";
//	}
//	conjugate1 = c1.Conjugate();
//	cout << "Conjugate of c1:  ";
//	conjugate1.Output();
//	conjugate2 = c2.Conjugate();
//	cout << "Conjugate of c2:  ";
//	conjugate2.Output();
//	sum = c1.Add(c2);
//	sub = c1.Subtract(c2);
//	mul = c1.Multiply(c2);
//	cout << "c1+c2=   ";
//	sum.Output();
//	cout << "c1-c2=   ";
//	sub.Output();
//	cout << "c1xc2=   ";
//	mul.Output();
//	a = c1.Magnitude();
//	b = c2.Magnitude();
//	cout << "Magnitude of c1=   " << a << endl;
//	cout << "Magnitude of c2=   " << b << endl;
//
//}