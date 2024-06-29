#include <iostream>
using namespace std;
template <class v,class k>
struct TNode
{
    k key;
    v value;
    TNode<v,k>* leftChild;
    TNode<v,k>* rightChild;

    TNode(v val,k data)
    {
        value = val;
        key = data;
        leftChild = rightChild = 0;
    }
};

template <class v,class k>
class BST
{
private:
    TNode<v,k>* root;

    void copyTreeNode(TNode<v,k>*& dest, TNode<v,k>* src)
    {
        if (src != nullptr)
        {
            dest = new TNode<v,k>(src->value);
            copyTreeNode(dest->leftChild, src->leftChild);
            copyTreeNode(dest->rightChild, src->rightChild);
        }
    }

    void destroyTreeNode(TNode<v,k>* current)
    {
        if (current != nullptr)
        {
            destroyTreeNode(current->leftChild);
            destroyTreeNode(current->rightChild);
            delete current;
        }
    }
    void inorder(TNode<v,k>* root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->leftChild);
        cout << "| " << root->value << ", " << root->key << " |\n";
        inorder(root->rightChild);
    }
    int NodesOfTree(TNode<v,k>* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int LeftNodes = NodesOfTree(node->leftChild);
        int rightNodes = NodesOfTree(node->rightChild);
        return 1 + LeftNodes + rightNodes;
    }

    int heightOfTree(TNode<v,k>* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftHeight = heightOfTree(node->leftChild);
        int rightHeight = heightOfTree(node->rightChild);
        if (leftHeight > rightHeight)
        {
            return 1 + leftHeight;
        }
        return 1 + rightHeight;
    }

    int LeafOfTree(TNode<v,k>* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        if (node->leftChild == nullptr && node->rightChild == nullptr)
        {
            return 1;
        }
        return LeafOfTree(node->leftChild) + LeafOfTree(node->rightChild);
    }

public:
    BST()
    {
        root = 0;
    }

    BST(const BST<v,k>& other)
    {
        root = nullptr;
        copyTreeNode(root, other.root);
    }
    TNode<v,k>* insertTreeNode(TNode<v,k>* node, v value,k key)
    {
        if (node == nullptr)
        {
            return new TNode<v, k>(value, key);
        }
        if (key == node->key)
        {
            node->value = value;
            return node;
        }
        if (value < node->value)
        {
            node->leftChild = insertTreeNode(node->leftChild, value,key);
        }
        else if (value > node->value)
        {
            node->rightChild = insertTreeNode(node->rightChild, value,key);
        }
        return node;
    }
    void insertRec(v value,k key)
    {
        root = insertTreeNode(root, value, key);
    }
    void insert(v value,k key)
    {
        insertRec(value, key);
    }
    void inorderPrintkeys()
    {
        inorder(root);
    }

    int NumberOfNodes() 
    {
        return NodesOfTree(root);
    }

    int Height() 
    {
        return heightOfTree(root);
    }

    int Leaf()
    {
        return LeafOfTree(root);
    }
    ~BST()
    {
        destroyTreeNode(root);
    }
    
};

void main()
{
    BST<int, int> tree;
    tree.insert(500, 500); //value,key
    tree.insertRec(1000, 1000);
    tree.insert(1, 1);
    tree.insert(600, 600);
    tree.insertRec(700, 700);
    tree.insert(10, 10);
    tree.insert(30, 30);
    tree.insertRec(9000, 9000);
    tree.insert(50000, 50000);
    tree.insertRec(20, 20);
    cout << "Number Of Nodes Of Tree= " << tree.NumberOfNodes() << endl;
    cout << "Number of tree LeafNodes=" << tree.Leaf() << endl;
    cout << "Height Of Tree is: " << tree.Height() << endl;
    cout << "Printing keys using iterative inorder traversal:\n";
    tree.inorderPrintkeys();
}