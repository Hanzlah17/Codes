#include <iostream>

using namespace std;

template <typename T>
class list
{
    class node
    {
    public:
        T data;
        node* next;

        node() : next(nullptr) {}
        node(const T& item, node* ptr = nullptr)
        {
            data = item;
            next = ptr;
        }
    };
private:
    node* head;
    node* tail;

public:
    list()
    {

        head = tail = 0;
    }
    void TraverseList()
    {
        for (auto itr = begin(); itr != end(); itr++)
        {
            cout << "| " << *itr << " |->";
        }
        cout << *end() << "\n";
    }
    void PrintNthnode(int n)
    {
        int i = 1;
        auto itr = begin();
        for (itr;i < n && itr != end();itr++, i++)
        {
        }
        cout << "| " << *itr << " |\n";
    }
    bool Search(const T& element)
    {
        auto itr = begin();
        for (auto itr = begin(); itr != end(); itr++)
        {
            if (*itr == element)
            {
                return true;
            }
        }
        return false;
    }
    ~list()
    {
        auto itr = begin();
        auto itr2 = begin();
        while (itr != end())
        {
            itr2 = itr;
            itr++;
            delete itr2.nodePtr;
        }
        delete itr.nodePtr;
    }

    // Inner class iterator
    class iterator
    {
        friend class list;

    private:
        node* nodePtr;

        iterator(node* newPtr) : nodePtr(newPtr) {}

    public:
        iterator() : nodePtr(nullptr) {}

        bool operator!=(const iterator& itr) const
        {
            return nodePtr != itr.nodePtr;
        }

        // Overload for the dereference operator *
        T& operator*() const
        {
            return nodePtr->data;
        }
        bool operator==(const iterator& itr)
        {
            return(nodePtr == itr.nodePtr);
        }
        // Overload for the postincrement operator ++
        iterator operator++(int)
        {
            iterator temp = *this;
            nodePtr = nodePtr->next;
            return temp;
        }
    };

    iterator begin() const
    {
        return head;
    }
    void InsertAtBeginning(T data)
    {
        node* nn = new node(data, head);
        if (!head)
        {
            head = nn;
            tail = nn;
            return;
        }
        head = nn;
        tail->next = head;
    }
    void InsertAtEnd(T data)
    {
        node* nn = new node(data, head);
        if (!head)
        {
            head = nn;
        }
        if (tail)
        {
            tail->next = nn;
        }
        tail = nn;
    }
    void DeleteFromBeginning()
    {
        if (head)
        {
            node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }
        cout << "Link List is Empty\n";
    }
    void DeleteAtEnd()
    {
        if (tail)
        {
            auto iprevious = begin();
            for (auto itr = begin();itr != end();itr++)
            {
                iprevious = itr;
            }
            node* temp = tail;
            tail = iprevious.nodePtr;
            tail->next = head;
            delete temp;
            return;
        }
        cout << "Link List is Empty\n";
    }
    void DeleteNode(T data)
    {
        if (head->data == data)
        {
            DeleteFromBeginning();
            return;
        }
        if (tail->data == data)
        {
            DeleteAtEnd();
            return;
        }
        auto itr = begin();
        auto iprev = begin();
        while (itr != end())
        {
            iprev = itr;
            itr++;
            if (*itr == data)
            {
                break;
            }
        }
        iprev.nodePtr->next = itr.nodePtr->next;
        delete itr.nodePtr;
    }
    void DeleteNext(iterator ptr)
    {
        ptr++;
        DeleteNode(*ptr);
    }
    iterator end() const
    {
        return tail;
    }
    void MidList()
    {
        int count = 1;
        for (auto itr = begin();itr != end();itr++)
        {
            count++;
        }
        count = count / 2;
        PrintNthnode(count);
    }
};
list<int>* MergeList(list<int>* ll1, list<int>* ll2)
{
    list<int>* uni = new list<int>;
    auto i = ll1->begin();
    auto j = ll2->begin();
    while (i != ll1->end() && j != ll2->end())
    {
        if (*i < *j)
        {
            uni->InsertAtEnd(*i);
            i++;
        }
        else
        {
            uni->InsertAtEnd(*j);
            j++;
        }
    }
    while (i != ll1->end())
    {
        uni->InsertAtEnd(*i);
        i++;
    }
    while (j != ll2->end())
    {
        uni->InsertAtEnd(*j);
        j++;
    }
    if (*i < *j)
    {
        uni->InsertAtEnd(*i);
        uni->InsertAtEnd(*j);
    }
    else
    {
        uni->InsertAtEnd(*j);
        uni->InsertAtEnd(*i);
    }
    return uni;
}
void Append(list<int>* ll1, list<int>* ll2)
{
    for (auto itr = ll2->begin(); itr != ll2->end();itr++)
    {
        ll1->InsertAtEnd(*itr);
    }
    int data = *(ll2->end());
    ll1->InsertAtEnd(data);
}
void CheckList(list<int>* ll)
{
    auto itr = ll->begin();
    auto itr2 = ll->end();
    itr2++;
    if (itr == itr2)
    {
        cout << "Link list is Circular\n";
    }
    else
    {
        cout << "Link List is not Circular\n";
    }
}
int main()
{
    list<int> ll;
    ll.InsertAtBeginning(6);
    ll.InsertAtBeginning(5);
    ll.InsertAtBeginning(4);
    ll.InsertAtBeginning(3);
    ll.InsertAtBeginning(2);
    ll.InsertAtBeginning(19);
    ll.InsertAtBeginning(1);
    cout << "------------------------\n";
    ll.TraverseList();
    ll.InsertAtEnd(7);
    ll.InsertAtEnd(8);
    ll.InsertAtEnd(9);
    cout << "------------------------\n";
    ll.TraverseList();
    ll.DeleteNode(9);
    cout << "------------------------\n";
    ll.TraverseList();
    ll.DeleteNode(19);
    cout << "------------------------\n";
    ll.TraverseList();
    auto itr = ll.begin();
    while (*itr != 5)
    {
        itr++;
    }
    ll.DeleteNext(itr);
    ll.DeleteNode(5);
    cout << "------------------------\n";
    ll.TraverseList();
    if (ll.Search(3))
    {
        cout << "Node was found\n";
        ll.PrintNthnode(3);
    }
    cout << "---------MID LIST-------\n";

    ll.MidList();
    cout << "------------------------\n";
    ll.TraverseList();
    list<int> cl1;
    list<int> cl2;
    cl1.InsertAtEnd(10);
    cl1.InsertAtEnd(30);
    cl1.InsertAtEnd(50);
    cl1.InsertAtEnd(80);
    cout << "Circular Link List 1\n";
    cl1.TraverseList();
    cl2.InsertAtEnd(20);
    cl2.InsertAtEnd(40);
    cl2.InsertAtEnd(60);
    cl2.InsertAtEnd(70);
    cout << "Circular Link List 2\n";
    cl2.TraverseList();
    list<int>* merged = MergeList(&cl1, &cl2);
    cout << "----------Merged List-------\n";
    merged->TraverseList();
    Append(&cl1, &cl2);
    cout << "-----------After Appending List1-------\n";
    cl1.TraverseList();
    CheckList(&cl1);
    return 0;
}