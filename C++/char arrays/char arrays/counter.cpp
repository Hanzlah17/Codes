//#include <iostream>
//using namespace std;
//void counter(char a[])
//{
//	int c = 0;
//	for (int i = 0;a[i] != '\0';i++)//space counter
//	{
//		if (a[i] == ' ')
//		{
//			c++;
//		}
//	}
//	cout << "The spaces in sentence= " << c << endl;
//	c = 0;
//	for (int i = 0;a[i] != '\0';i++) //punctuation mark counter
//	{
//		if ((a[i] >= 33 && a[i] <= 64) || (a[i] >= 91 && a[i] <= 96) || (a[i] >= 123 && a[i] <= 126))
//		{
//			c++;
//		}
//	}
//	cout << "The punctuation marks in sentence= " << c << endl;
//	c = 0;
//	for (int i = 0;a[i] != '\0';i++)//alphabet counter
//	{
//		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
//		{
//			c++;
//		}
//	}
//	cout << "The alphabets in sentence= " << c << endl;
//}
//int main()
//{
//	char a[50];
//	cout << "Enter a message : ";
//	gets_s(a, 50);
//	counter(a);
//}