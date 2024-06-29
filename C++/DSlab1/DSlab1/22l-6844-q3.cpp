//#include<iostream>
//#include<conio.h>
//using namespace std;
//class Calculator
//{
//public:
//	virtual void Input(){}
//	virtual void add(){}
//	virtual void subtract(){}
//	virtual void multiply() {}
//	virtual void divide(){}
//};
//class SimpleNumber:public Calculator
//{
//	int a;
//	int b;
//public:
//	void Input()
//	{
//		cout << "Enter the first number: ";
//		cin >> a;
//		cout << "Enter the second number: ";
//		cin >> b;
//	}
//	void add()
//	{
//		cout << a + b << endl;
//	}
//	void subtract()
//	{
//		cout << a - b << endl;
//	}
//	void multiply()
//	{
//		cout << a * b << endl;
//	}
//	void divide()
//	{
//		cout << a / b << endl;
//	}
//};
//class ComplexNum
//{
//private:
//	int real;
//	int imaginary;
//public:
//	ComplexNum()
//	{
//		real = 0;
//		imaginary = 0;
//	}
//	void Input()
//	{
//		cout << "Enter real:";
//		cin >> real;
//		cout << "Enter imaginary: ";
//		cin >> imaginary;
//	}
//	void Print()
//	{
//		if (!real)
//		{
//			if (imaginary)
//			{
//				cout << imaginary << "i";
//			}
//		}
//		else
//		{
//			cout << real;
//			if (imaginary >= 0)
//			{
//				cout << " + ";
//			}  
//			cout << imaginary << "i";
//		}
//	}
//	void Add(const ComplexNum a)
//	{
//		ComplexNum res;
//		res.real = real + a.real;
//		res.imaginary = imaginary + a.imaginary;
//		res.Print();
//		cout << "\n";
//	}
//	void Sub(const ComplexNum a)
//	{
//		ComplexNum res;
//		res.real = real - a.real;
//		res.imaginary = imaginary - a.imaginary;
//		res.Print();
//		cout << "\n";
//	}
//	void Mul(const ComplexNum a)
//	{
//		ComplexNum res;
//		res.real = real * a.real - imaginary * a.imaginary;
//		res.imaginary = imaginary * a.real + real * a.imaginary;
//		res.Print();
//		cout << "\n";
//	}
//	void Div(const ComplexNum a)
//	{
//		ComplexNum res;
//		res.real = (real * a.real + imaginary * a.imaginary) / a.real ^ 2 + a.imaginary ^ 2;
//		res.imaginary = (imaginary * a.real - real * a.imaginary) / a.real ^ 2 + a.imaginary ^ 2;
//		res.Print();
//		cout << "\n";
//	}
//};
//class ComplexNumber:public Calculator
//{
//
//	ComplexNum a;
//	ComplexNum b;
//public:
//	void Input()
//	{
//		a.Input();
//		b.Input();
//	}
//	void add()
//	{
//		a.Add(b);
//	}
//	void subtract()
//	{
//		a.Sub(b);
//	}
//	void multiply()
//	{
//		a.Mul(b);
//	}
//	void divide()
//	{
//		a.Div(b);
//	}
//};
//void main()
//{
//	Calculator** array;
//	int size;
//	cout << "Enter the required number: ";
//	cin >> size;
//	array = new Calculator * [size];
//	int i = 0;
//	while (i < size)
//	{
//		cout << "press 1 for simple and 2 for Complex Number: ";
//		switch (_getch())
//		{
//		case '1':
//			cout << "Simple Number added\n";
//			array[i] = new SimpleNumber[1];
//			i++;
//			break;
//		case '2':
//			cout << "Complex Number added\n";
//			array[i] = new ComplexNumber[1];
//			i++;
//			break;
//		default:
//			cout << "Default: Please enter 1 or 2." << endl;
//			break;
//		}
//		
//	}
//	for (int i = 0;i < size;i++)
//	{
//		array[i]->Input();
//		array[i]->add();
//		array[i]->subtract();
//		array[i]->multiply();
//		array[i]->divide();
//
//	}
//	for (int i = 0;i < size;i++)
//	{
//		delete[] array[i];
//	}
//	delete[] array;
//}