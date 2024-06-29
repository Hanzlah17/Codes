//#include <iostream>
//
//using namespace std;
//
//template <typename T>
//class list
//{
//    class node
//    {
//    public:
//        T data;
//        node* next;
//
//        node() : next(nullptr) {}
//        node(const T& item, node* ptr = nullptr)
//        {
//            data = item;
//            next = ptr;
//        }
//    };
//private:
//    node* head;
//    node* tail;
//
//public:
//    list()
//    {
//
//        head = tail = new node;
//    }
//    void Print()
//    {
//        for (auto itr = begin(); itr != end(); itr++)
//        {
//            cout << *itr << "->";
//        }
//    }
//    void PrintNthnode(int n)
//    {
//        int i = 0;
//        auto itr = begin();
//        for (itr;i < n&& itr != end();itr++, i++)
//        {
//        }
//        cout << "| " << *itr << " |\n";
//    }
//    bool Search(const T& element)
//    {
//        auto itr = begin();
//        for (auto itr = begin(); itr != end(); itr++)
//        {
//            if (*itr == element)
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//    void DeleteStart()
//    {
//        if (begin())
//        {
//            node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//        else
//        {
//            cout << "link list is empty";
//        }
//    }
//    T Sum()
//    {
//        int sum = 0;
//        for (auto itr = begin();itr != end();itr++)
//        {
//            sum = sum + *itr;
//        }
//        return sum;
//    }
//    void Sort()
//    {
//        for (auto i = begin();i != end();i++)
//        {
//            for (auto j = i;j != end();j++)
//            {
//                if (*j < *i)
//                {
//                    T temp = *i;
//                    *i = *j;
//                    *j = temp;
//                }
//            }
//        }
//    }
//    list* Union(list* l2)
//    {
//        Sort();
//        l2->Sort();
//        list* uni = new list;
//        auto i = begin();
//        auto j = l2->begin();
//        while (i != end() && j != l2->end())
//        {
//            if (*i < *j)
//            {
//                if (!uni->Search(*i))
//                {
//                    uni->insert(uni->end(), *i);
//                }
//                i++;
//            }
//            else
//            {
//                if (!uni->Search(*j))
//                {
//                    uni->insert(uni->end(), *j);
//                }
//                j++;
//            }
//        }
//        while (i != end())
//        {
//            if (!uni->Search(*i))
//            {
//                uni->insert(uni->end(), *i);
//            }
//            i++;
//        }
//        while (j != l2->end())
//        {
//            if (!uni->Search(*j))
//            {
//                uni->insert(uni->end(), *j);
//            }
//            j++;
//        }
//        return uni;
//    }
//    ~list()
//    {
//        while (head->next != nullptr)
//        {
//            node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//        delete head;
//    }
//
//    // Inner class iterator
//    class iterator
//    {
//        friend class list;
//
//    private:
//        node* nodePtr;
//
//        iterator(node* newPtr) : nodePtr(newPtr) {}
//
//    public:
//        iterator() : nodePtr(nullptr) {}
//
//        bool operator!=(const iterator& itr) const
//        {
//            return nodePtr != itr.nodePtr;
//        }
//
//        // Overload for the dereference operator *
//        T& operator*() const
//        {
//            return nodePtr->next->data;
//        }
//
//        // Overload for the postincrement operator ++
//        iterator operator++(int)
//        {
//            iterator temp = *this;
//            nodePtr = nodePtr->next;
//            return temp;
//        }
//    }; // End of inner class iterator
//
//    iterator begin() const
//    {
//        return head;
//    }
//
//    iterator end() const
//    {
//        return tail;
//    }
//
//    iterator insert(iterator position, const T& value)
//    {
//        node* newNode = new node(value, position.nodePtr->next);
//        if (position.nodePtr == tail)
//            tail = newNode;
//        position.nodePtr->next = newNode;
//        return position;
//    }
//
//    iterator erase(iterator position)
//    {
//        node* toDelete = position.nodePtr->next;
//        position.nodePtr->next = position.nodePtr->next->next;
//        if (toDelete == tail)
//            tail = position.nodePtr;
//        delete toDelete;
//        return position;
//    }
//};
//
//int main()
//{
//    list<int> v;
//    list<int> x;
//    v.insert(v.end(), 2);
//    v.insert(v.end(), 4);
//    v.insert(v.end(), 5);
//    x.insert(x.end(), 11);
//    x.insert(x.end(), 11);
//    x.insert(x.end(), 12);
//    x.insert(x.end(), 2);
//    x.insert(x.end(), 10);
//    x.insert(x.end(), 5);
//    auto iter = v.begin();
//    iter = v.insert(iter, 1); 
//    iter++;                 
//    v.insert(iter, 3);   
//    iter++;                   
//    v.insert(iter, 10);       
//    iter = v.begin();
//    iter++;
//    cout << "\nUnsorted List:\n";
//    v.Print();
//    cout << "\nElement " << *iter << " removed from the list\n";
//    v.erase(iter);
//    cout << "List after removing element:\n";
//    v.Print();
//    cout << "\nSorted List:\n";
//    v.Sort();
//    v.Print();
//    cout << endl;
//    cout << "Node at 3rd index:\n";
//    v.PrintNthnode(3);
//    cout << "\nSum of List is: " << v.Sum() << endl;
//    cout << "List1\n";
//    v.Print();
//    cout << "\nlist2\n";
//    x.Print();
//    list<int>* uni = v.Union(&x);
//    cout << "\nUNION\n";
//    uni->Print();
//    delete uni;
//    return 0;
//}