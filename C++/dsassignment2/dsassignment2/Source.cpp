#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right;
	node(int val)
	{
		data = val;
		left = right = 0;
	}

};
int sum(node* root)
{
	if (!root)
	{
		return false;
	}
	return sum(root->left) + root->data + sum(root->right);
}

int isSumTree(node* node)
{
	int leftsum, rightsum;
	if (!node)
	{
		return true;
	}

	leftsum = sum(node->left);

	rightsum = sum(node->right);
	if ((node->data == leftsum + rightsum) && isSumTree(node->left) && isSumTree(node->right))
	{
		return true;
	}
	return false;
}
node* newNode(int data)
{

	node* nnode = new node(data);
	return nnode;
}

int main()
{

	node* root = newNode(44);

	root->left = newNode(9);

	root->right = newNode(13);

	root->left->left = newNode(4);

	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);



	if (isSumTree(root))
	{
		cout << "The given tree is a SumTree ";
	}
	else
	{
		cout << "The given tree is not a SumTree ";
	}
	return 0;
}