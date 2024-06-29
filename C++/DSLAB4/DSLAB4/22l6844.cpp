#include <iostream>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T>* next;

public:
    node()
    {
        data = 0;
        next = nullptr;
    }
};

template <typename T>
class LL
{
    node<T>* head;
    friend bool isSorted(LL<int>*);
    friend void MergeList(LL<int>*, LL<int>*,LL<int>*);
public:
    LL()
    {
        head = nullptr;
    }

    void add(T item)
    {
        node<T>* nn = new node<T>;
        nn->data = item;
        if (head == nullptr)
        {
            head = nn;
            cout << "new node added at first" << endl;
            return;
        }

        node<T>* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = nn;
    }
    void InsertAtEnd(T item)
    {
        add(item);
    }
    void InsertAtStart(T item)
    {
        node<T>* nn = new node<T>;
        nn->data = item;
        if (head == nullptr)
        {
            head = nn;
            cout << "new node added at first" << endl;
            return;
        }
        nn->next = head;
        head = nn;
    }
    bool Search(const T& element)
    {
        node<T>* temp = head;
        while (temp)
        {
            if (temp->data == element)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    bool Search(const T& element, int& index)
    {
        node<T>* temp = head;
        index = 0;
        while (temp)
        {
            if (temp->data == element)
            {
                return true;
            }
            index++;
            temp = temp->next;
        }
        return false;
    }
    bool isEmpty()
    {
        return !head;
    }
    int length()
    {
        int len = 0;
        node<T>* temp = head;
        while (temp != nullptr)
        {

            len++;
            temp = temp->next;
        }
        return len;
    }

    void InsertAtIndex(int index, T item)
    {
        if (index > length() || index < 0)
        {
            cout << "index out of bound" << endl;
            return;
        }

        node<T>* nn = new node<T>;
        nn->data = item;
        int count = 0;
        node<T>* temp = head;
        while (temp != nullptr && count < index)
        {
            if (count == index - 1)
            {
                if (temp->next != nullptr)
                {
                    nn->next = temp->next;
                }
                temp->next = nn; // or you can call add() function.. i have moved this statement after if to handle insertion at end.
            }
            count++;
            temp = temp->next;
        }
    }

    void Print()
    {
        if (head == NULL)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        cout << endl
            << "----link list items------" << endl;
        node<T>* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " | ";
            temp = temp->next;
        }
        cout << endl
            << "--------------------------" << endl;
    }
    void InsertAfterValue(T value, T item)
    {
        node<T>* nn = new node<T>;
        nn = head;
        int index = 0;
        bool found = 0;
        while (nn && !found)
        {
            if (nn->data == value)
            {
                found = 1;
            }
            else
            {
                index++;
                nn = nn->next;
            }
        }
        if (found)
        {
            add(index + 1, item);
        }
        else
        {
            cout << "Value not found!!Node wasn't added\n";
        }
    }
    void DeleteStart()
    {
        if (head)
        {
            node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            cout << "link list is empty";
        }
    }
    void RemoveatIndex(int index)
    {
        if (head)
        {
            if (index > length() || index < 0)
            {
                cout << "index out of bound" << endl;
                return;
            }
            node<T>* nn = new node<T>;
            nn = head;
            int count = 0;
            if (index == 0)
            {
                DeleteStart();
                return;
            }
            while (count < index - 1)
            {
                nn = nn->next;
                count++;
            }
            node<T>* temp = nn->next;
            nn->next = (nn->next)->next;
            delete temp;
        }
        else
        {
            cout << "Link list is empty\n";
        }
    }
    void DeleteAll(const T& value)
    {
        if (Search(value))
        {
            int index = 0;
            while (Search(value, index))
            {
                RemoveatIndex(index);
            }
        }
        else
        {
            cout << "value is not in the list\n";
        }
    }
    void sortList()
    {

        node<T>* current = head;
        node<T>* index = NULL;
        int temp;

        if (isEmpty())
        {
            return;
        }
        else
        {
            while (current)
            {
                index = current->next;

                while (index)
                {
                    if (current->data > index->data)
                    {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
    void removeDuplicates()
    {

        if (isEmpty() || head->next == nullptr)
        {
            return;
        }
        sortList(this);
        node<T>* tnext, * temp;
        temp = head;

        while (temp->next != nullptr)//this logic will work if list is sorted
        {
            if (temp->data == temp->next->data)
            {
                tnext = temp->next->next;
                delete temp->next;
                temp->next = tnext;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    LL<T>* Merge(LL<T>*& list2)
    {
        node<T>* temp1 = head;
        node<T>* temp2 = list2->head;
        LL<T>* result = new LL<T>;
        result->head = new node<T>;
        while (temp1)
        {
            result->add(temp1->data);// call insert function here
            temp1 = temp1->next;
        }
        while (temp2)
        {
            result->add(temp2->data);// call insert function here
            temp2 = temp2->next;
        }
        result->sortList();
        return result;
    }
    void DeleteEnd()
    {
        int index = length() - 1;
        RemoveatIndex(index);
    }
    ~LL()
    {
        while (head)
        {
            DeleteStart();
        }
    }
};
//------NOTE FOR FOLLOWING FUNCTIONS-----------//
//To make a global function with same template used in class was out of my knowledge. I faced "Unresolved Externals" error when I make another template on these global functions. Hence I hard coded them with "int"
bool isSorted(LL<int>* list) //checks only ascending sorted
{
    if (list->isEmpty() || !list->head->next)
    {
        return 0;
    }
    node<int>* temp = list->head;
    while (temp->next)
    {
        if (temp->data > temp->next->data)
        {
            return false;
        }
    }
    return true;

}
void MergeList(LL<int>* list1, LL<int>* list2,LL<int>* MergedList)
{
    list1->sortList();
    list2->sortList();
    node<int>* i = list1->head;
    node<int>* j = list2->head;
    while (i && j)
    {
        if (i->data < j->data)
        {
            MergedList->add(i->data);
            i = i->next;
        }
        else
        {
            MergedList->add(j->data);
            j = j->next;
        }
    }
    while (i)
    {
        MergedList->add(i->data);
        i = i->next;
    }
    while (j)
    {
        MergedList->add(j->data);
        j = j->next;
    }
}
int main()
{
    LL<int> list;
    list.add(2);
    list.add(6);
    list.add(7);
    list.InsertAtEnd(9);
    list.InsertAtStart(7);
    list.InsertAtStart(8);
    list.InsertAtStart(9);
    list.Print();
    list.DeleteAll(7);
    list.Print();
    if (list.Search(2))
    {
        cout << "found!!\n";
    }
    else
    {
        cout << "Not found!!\n";
    }
    if (list.Search(9))
    {
        cout << "found!!\n";
    }
    else
    {
        cout << "Not found!!\n";
    }
    if (list.Search(10))
    {
        cout << "found!!\n";
    }
    else
    {
        cout << "Not found!!\n";
    }
    list.DeleteStart();
    cout << "----------------LIST1-------------------\n";
    list.Print();
    LL<int> list2;
    list2.add(10);
    list2.add(0);
    list2.add(-10);
    list2.add(100);
    list2.add(7);
    cout << "----------------LIST2-------------------\n";
    list2.Print();
    LL<int> list3;
    MergeList(&list, &list2,&list3);
    cout << "----------------LIST3-------------------\n";
    list3.Print();
}