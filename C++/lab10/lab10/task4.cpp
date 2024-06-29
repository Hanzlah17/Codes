#include<iostream>
#include<stdio.h>
using namespace std;
void reverse(char a[],int i,int s)
{
	for(int j=0;j!=i;j++)
	{
		swap(a[i],a[j]);
		i--;
	}
}
int main()
{
	char a[50];
	int c=0,in,ch=0;
	cout<<"Enter a sentence: ";
	cin>>a;
	for(int i=0;a[i]!='.';i++)
	{
		c++;
		if(a[i]==' ')
		{
			in=c-2;
			reverse(a,in,ch);
		}
		ch=c;
	}
	cout<<"The reversed text : ";
	cout<<a;
}
