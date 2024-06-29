#include<iostream>
using namespace std;
int StringLength(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
void toLower(char& a)
{
	if (a >= 65 && a <= 90)
	{
		a = a + 32;
	}
}
bool CompareChar(char a, char b)
{
	toLower(a);
	toLower(b);
	if (a < b)
	{
		return 1;
	}
	return 0;
}
class MyString
{
	friend istream& operator>>(istream&, MyString&);
	friend ostream& operator<<(ostream&, const MyString&);
private:
	char* str;
	int lenght;	//not including the null char here
	char* GetStringFromBuffer(char* temp)
	{
		int len = StringLength(temp);
		char* arr = new char[len + 1];
		int i = 0;
		while (temp[i] != '\0')
		{
			arr[i] = temp[i];
			i++;
		}
		arr[i] = '\0';
		return arr;
	}
	char* StringConcatenate(char* str1, char* str2)
	{
		int l1 = StringLength(str1);
		int l2 = StringLength(str2);
		int size = l1 + l2;
		size = size + 1;
		char* temp = new char[size];
		int k = 0, i = 0;
		for (int i = 0;str1[i] != '\0';i++)
		{
			temp[k] = str1[i];
			k++;
		}
		for (int i = 0;str2[i] != '\0';i++)
		{
			temp[k] = str2[i];
			k++;
		}
		temp[k] = '\0';
		return temp;
	}
	bool CompareString(char* str1, char* str2)
	{
		bool b = 0;
		for (int i = 0;str1[i] != '\0' && str2[i] != '\0' && b == 0;i++)
		{
			b = CompareChar(str1[i], str2[i]);
		}
		return b;
	}
	//You can add your class members here
public:

	//-------------DO_NOT_CHANGE REGION starts below---------------------
	//Do not change the prototypes given below
	MyString operator+(const MyString);
	MyString& operator=(const MyString&);
	bool operator<(MyString);	//Comparison on the basis of ascii values
	//-------------End of DO_NOT_CHANGE REGION---------------------
	MyString()
	{
		str = new char('\0');
		lenght = 0;
	}
	MyString(const MyString& a)
	{
		str = new char('\0');
		char* temp = StringConcatenate(str, a.str);
		delete str;
		str = temp;
		lenght = a.lenght;
	}
	~MyString()
	{
		delete[] str;
	}
	bool operator!()
	{
		return(!lenght);
	}
	char& operator[](int a)
	{
		if (a < lenght)
		{
			return str[a];
		}
		else
		{
			throw "OUT OF RANGE";
		}
	}
	MyString operator()(int st, int len)
	{
		MyString temp;
		temp.lenght = len;
		delete temp.str;
		temp.str = new char[len + 1];
		int j = 0;
		for (int i = st;j < len && str[i] != '\0';i++,j++)
		{
			temp.str[j] = str[i];
		}
		temp.str[j] = '\0';
		return temp;
	}

};
MyString MyString::operator+(const MyString a)
{
	MyString temp;
	delete temp.str;
	temp.str = StringConcatenate(str, a.str);
	temp.lenght = lenght + a.lenght;
	return temp;
}
MyString& MyString::operator=(const MyString& a)
{
	if (&a != this)
	{
		char* temp = StringConcatenate(str, a.str);
		delete str;
		str = temp;
		lenght = a.lenght;
	}
	return *this;
}
bool MyString:: operator<(MyString a)
{
	return(CompareString(str, a.str));
}
istream& operator>>(istream& cin, MyString& a)
{
	char temp[80];
	cin.getline(temp, 80);
	delete a.str;
	a.str = a.GetStringFromBuffer(temp);
	a.lenght = StringLength(a.str);
	return cin;
}
ostream& operator<<(ostream& obj, const MyString& a)
{
	obj << a.str;
	return obj;
}
//-------------DO_NOT_CHANGE REGION starts below---------------------
void main()
{
	MyString str1, str2, str3, str4;	//Default constructor will make a string of lenght 0 but having null character (only) i.e. empty string

	if (!str1)
	{
		cout << "String 1 is Empty.\n";
		cout << "Str 1 = " << str1 << endl << endl << endl;
	}

	cout << "Enter String 1:\t";
	cin >> str1;


	cout << "Enter String 2:\t";
	cin >> str2;


	cout << "\n\n\nUser Entered:\n";
	cout << "String 1 = " << str1 << endl;
	cout << "String 2 = " << str2 << endl << endl << endl;

	//What is following code testing?
	cout << "Before str1 = str1; str1 = " << str1 << endl;
	str1 = str1;
	cout << "After str1 = str1, str1 = " << str1 << endl << endl << endl;


	cout << "Before str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	str4 = str3 = str1 + str2;


	cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	cout << "\n\n\nEnter String 3:\t";
	cin >> str3;

	cout << "\n\n\nEnter String 4:\t";
	cin >> str4;


	cout << "\n\n\nstr3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	if (str3 < str4)
		cout << "String 3 is Less than String 4.\n";
	else
		cout << "String 3 is NOT Less than String 4.\n";

	MyString str5 = str1 + str2;
	cout << "\n\n\nStr5:\t" << str5 << endl;
	cout << "Str5[7]:\t" << str5[7] << endl; //Function Call: str5.operator[](7).
	str5[7] = '$';

	cout << "\n\nStr5:\t" << str5 << endl;

	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;// Substring of lenght 10 starting from index 5 . Function Call str5.operator()(5,10) Let the returned MyString or char* leak

}
//-------------End of DO_NOT_CHANGE REGION---------------------

