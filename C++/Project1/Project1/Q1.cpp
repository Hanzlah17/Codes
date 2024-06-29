//#include <iostream>
//using namespace std;
//int main()
//{
//	float r, l, w, b, h,pi=3.14159,area;
//	int a;
//	cout << "Geometry Calculator\n";
//	cout << "1.Calculate the area of a circle\n2.Calculate the area of a rectangle\n3.Calculate the area of a triangle\n";
//	cin >> a;
//	while (a < 1 || a>3)
//	{
//		cout << "press a valid key assigned in menu\n";
//		cout << "Geometry Calculator\n";
//		cout << "1.Calculate the area of a circle\n2.Calculate the area of a rectangle\n3.Calculate the area of a triangle\n";
//		cin >> a;
//	}
//	if (a == 1)
//	{
//		cout << "Enter the radius of circle= \n";
//		cin >> r;
//		while (r < 0)
//		{
//			cout << "Enter a positive value= \n";
//			cout << "Enter the radius of circle= \n";
//			cin >> r;
//		}
//		area = pi * r;
//		cout << "The area of circle= " << area;
//	}
//	else if (a == 2)
//	{
//		cout << "Enter the length of rectangle= \n";
//		cin >> l;
//		while (l < 0)
//		{
//			cout << "Enter a positive value= \n";
//			cout << "Enter the length of rectangle= \n";
//			cin >> l;
//		}
//		cout << "Enter the width of rectangle= \n";
//		cin >> w;
//		while (w < 0)
//		{
//			cout << "Enter a positive value= \n";
//			cout << "Enter the width of rectangle= \n";
//			cin >> w;
//		}
//		area = l * w;
//		cout << "The area of rectangle= " << area;
//	}
//	else
//	{
//		cout << "Enter the base of triangle= \n";
//		cin >> b;
//		while (b < 0)
//		{
//			cout << "Enter a positive value= \n";
//			cout << "Enter the base of triangle= \n";
//			cin >> b;
//		}
//		cout << "Enter the height of triangle= \n";
//		cin >> h;
//		while (h< 0)
//		{
//			cout << "Enter a positive value= \n";
//			cout << "Enter the height of triangle= \n";
//			cin >> h;
//		}
//		area = b * h* 0.5;
//		cout << "The area of triangle= " << area;
//	}
//}