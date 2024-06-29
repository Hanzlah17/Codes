#include<iostream>
using namespace std;
template <class T>
class Stack
{
private:
	T array[5];
	int size;
	int top;
public:
	Stack()
	{
		size = 5;
		top = -1;
	}
	void push(T entry)
	{
		top++;
		if (top == 5)
		{
			throw exception("stack overflow");
		}
		else
		{
			array[top] = entry;
		}
	}
	void pop()
	{

		if (top == -1)
		{
			throw exception("stack overflow");
		}
		else
		{
			top--;
		}
	}
};
void main()
{
	Stack<int> s;
	for (int i = 0;i < 5;i++)
	{
		s.push(i);
	}
	for (int i = 0;i < 5;i++)
	{
		s.pop();
	}
}