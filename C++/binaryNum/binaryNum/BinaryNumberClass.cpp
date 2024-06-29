#include<iostream>
using namespace std;
class BinaryNum
{
private:
	int* binNum; //integer array to save binary number
	int noOfBits; //total no. of bits
	//utility function
	int* stringTo(const char* a)
	{
		int size = strlen(a);
		int* res = new int[size];
		for (int i = 0;i<size;i++)
		{
			if (a[i] == 48)
			{
				res[i] = 0;
			}
			else
			{
				res[i] = 1;
			}
		}
		return res;
	}
	int Power(int number)
	{
		int r = 1;
		for (int i = 0;i < number;i++)
		{
			r = r * 2;
		}
		return r;
	}
	char* integerTo(int* a, int size)
	{
		char* res = new char[size+1];
		int i = 0;
		for (i = 0;i < size;i++)
		{
			if (a[i] == 0)
			{
				res[i] = '0';
			}
			else
			{
				res[i] = '1';
			}
		}
		return res;
	}
	BinaryNum DeciTo(int num)
	{
		int n = num;
		int c = 0;
		while (n >= 1)
		{
			n = n / 2;
			c++;
		}
		BinaryNum temp;
		temp.noOfBits = c;
		temp.binNum = new int[c];
		/*temp.binNum[0] = 1;*/
		c--;
		for (int i = c;num >= 1;i--)
		{
			temp.binNum[i] = num % 2;
			num = num / 2;
		}
		return temp;
	}
	int BinaryTo(const BinaryNum& a)
	{
		int ans = 0, j = 0;
		int i = a.noOfBits - 1;
		while (i >= 0)
		{
			if (a.binNum[j] == 1)
			{
				ans = ans + Power(i);
			}
			i--;
			j++;
		}
		return ans;
	}
public:
	BinaryNum()
	{
		noOfBits = 0;
		binNum = 0;
	}
	BinaryNum(const char* a)
	{
		noOfBits = strlen(a);
		binNum = stringTo(a);
	}
	void Print()
	{
		if (binNum != 0)
		{
			for (int i = 0; i < noOfBits; i++)
				cout << binNum[i];

		}
		cout << endl;
	}
	BinaryNum(const BinaryNum& a)
	{
		noOfBits = a.noOfBits;
		binNum = new int[noOfBits];
		for (int i = 0;i < noOfBits;i++)
		{
			binNum[i] = a.binNum[i];
		}
	}
	BinaryNum& operator=(const BinaryNum& a)
	{
		if (this != &a)
		{
			if (binNum)
			{
				delete[] binNum;
			}
			noOfBits = a.noOfBits;
			binNum = new int[noOfBits];
			for (int i = 0;i < noOfBits;i++)
			{
				binNum[i] = a.binNum[i];
			}
		}
		return *this;
	}
	BinaryNum operator+(BinaryNum a)
	{
		int ans = BinaryTo(*this) + BinaryTo(a);
		BinaryNum temp = DeciTo(ans);
		return temp;
	}
	int& operator[](int index)
	{
		if (index > -1 && index < noOfBits)
		{
			return binNum[index];
		}
		else
		{
			throw "Error";
		}
	}
	BinaryNum operator++(int)
	{
		BinaryNum temp("1");
		temp = temp + *this;
		return temp;
	}
	~BinaryNum()
	{
		if (binNum)
		{
			delete[] binNum;
		}
	}
};
BinaryNum operator+(const char* a, BinaryNum b)
{
	BinaryNum c(a);
	c = c + b;
	return c; 
}
void main()
{
	BinaryNum b1; //noOfBits = 0, binNum is NULL
	BinaryNum b2("101");//noOfBits = 3, binNum is {1,0,1}
	BinaryNum b3("1001"); //noOfBits = 4, binNum is {1,0,0,1}
	cout << "b1 = ";b1.Print(); //Prints Nothing
	cout << "b2 = ";b2.Print(); //Prints 101
	cout << "b3 = ";b3.Print(); //Prints 1001
	b1 = b2 + b3;
	cout << "b1 = ";b1.Print(); //Prints 1110
	cout << "b1[0] = " << b1[0] << endl; //Prints 1 (0th bit in b1)
	cout << "b1[3] = " << b1[3] << endl; //Prints 0 (3rd bit in b1)
	(b3++).Print(); //Prints 1001
	b3.Print(); //Prints 1010
	b1 = "111" + b2;
	b1.Print(); //Prints 1100
}