#include<iostream>
using namespace std;
class Polynomial
{
	friend ostream& operator<<(ostream&, Polynomial);
	friend Polynomial operator+(int,const Polynomial&);
private:
	int totalTerms;//Total terms in a Polynomial
	int* coeff;//to save array of coefficients
	int* expp; //to save array of exponents
	bool Check()
	{
		bool b = 1;
		for (int i = 0;i < totalTerms && b == 1;i++)
		{
			if (coeff[i] != 0)
			{
				b = 0;
			}
		}
		for (int i = 0;i < totalTerms && b == 1;i++)
		{
			if (expp[i] != 0)
			{
				b = 0;
			}
		}
		return b;
	}
	bool Compare(const Polynomial& a)
	{
		bool b = 1;
		if (totalTerms != a.totalTerms)
		{
			b = 0;
		}
		for (int i = 0;i < totalTerms && b == 1;i++)
		{
			if (coeff[i] != a.coeff[i] || expp != a.expp)
			{
				b = 0;
			}
		}
		return b;
	}
public:
	Polynomial(int a = 0, int* b = 0, int* c = 0)
	{
		totalTerms = a;
		coeff = b;
		expp = c;
	}
	bool operator!()
	{
		if (totalTerms > 1&& Check())
		{
			return true;
		}
		return false;
	}
	bool operator!=(const Polynomial& a)
	{
		return (Compare(a));
	}
	Polynomial operator+(const Polynomial& a)
	{
		int temp[10];
		int tem[10];
		int k = 0;
		int i = 0;
		for (int i = 0;i < totalTerms;i++)
		{
			for (int j = 0;j < a.totalTerms;j++)
			{
				if (expp[i] == a.expp[j])
				{
					temp[k] = coeff[i] + a.coeff[j];
					tem[k] = expp[i];
					k++;
				}
				else
				{

				}
			}
		}

		Polynomial b(k, temp, tem);
		return b;
	}

};
ostream& operator<<(ostream& cout, Polynomial a)
{
	for (int i = 0;i < a.totalTerms;i++)
	{
		if (a.coeff[i] >0)
		{
			if (a.coeff[i] > 1)
			{
				cout << a.coeff[i];
			}
			if (a.expp[i])
			{
				cout << "x";
			}
			if (a.expp[i] > 1)
			{
				cout << "^" << a.expp[i];
			}
			cout << "+";
		}
	}
	return cout;
}
Polynomial operator+(int n,const Polynomial& a)
{
	Polynomial b = a;
	int i = a.totalTerms;
	i--;
	b.coeff[i] = b.coeff[i] + n;
	return b;
}
void main()
{
	int coeff_P1[] = { 1,2,5 }; //Coefficients for Polynomial P1
	int exp_P1[] = { 4,2,0 }; //Exponents for Polynomial P1

	int coeff_P2[] = { 4,3 }; //Coefficients for Polynomial P2
	int exp_P2[] = { 6,2 }; //Exponents for Polynomial P2

	Polynomial P1(3, coeff_P1, exp_P1);//Creates P1 with 3 terms (P1 =1x ^ 4 + 2x ^ 2 + 5x ^ 0 )
	Polynomial P2(2, coeff_P2, exp_P2);//Creates P2 with 2 terms (P2 =4x ^ 6 + 3x ^ 2)

	cout<<"P1 = "<<P1<<endl; //Prints P1 = x^4+2x^2+5
	cout << "P2 = " << P2 << endl; //Prints P2 = 4x^6+3x^2
	if (!P1)
		cout << "P1 is zero" << endl;/*if polynomial has only 1 term and its coeff*/

	if (P1 != P2)

	cout << "P1 is Not Equal to P2" << endl;
	Polynomial P3 = P1 + P2; //Adds P1 and P2 and saves result inP3.You may consume extra space for resultant Polynomial in Add function
	cout << "P3 = " << P3 << endl; //Prints P3 = 4x^6+x^4+5x^2+5

	P3 = 2 + P1; //Assume P1 already has a constant term, add 2 in it.
	cout << "P3 = " << P3 << endl;
	//cout << "++P1 = " << ++P1 << endl; //adds 1 in all the coefficient.
	//cout << "P1 = " << P1 << endl;
	//cout << "P1++ = " << P1++ << endl;  //adds 1 in all the coefficient.
	//cout << "P1 = " << P1 << endl;
}