#include <iostream>
#include<string>
#include<fstream>
#include <cassert>
#include<sstream>
using namespace std;

template <class v>
struct HashItem
{
    int key;
    v value;
    short status;

    HashItem() : key(0), value(v()), status(0) {}
};

template <class v>
class HashMap
{
private:
    HashItem<v>* hashArray;
    int capacity;
    int currentElements;
    const double loadFactor = 0.75;

    int getNextCandidateIndex(int key, int i)
    {
        return (key + i) % capacity;
    }

    void doubleCapacity()
    {
        int prevcap = capacity;
        capacity *= 2;
        HashItem<v>* arr = hashArray;
        hashArray = new HashItem<v>[capacity];

        for (int i = 0; i < prevcap; ++i)
        {
            if (arr[i].status == 2)
            {
                int key = arr[i].key;
                int index = key % capacity;
                int j = 1;
                while (hashArray[index].status == 2)
                {
                    index = getNextCandidateIndex(key, j++);
                }
                hashArray[index] = arr[i];
            }
        }
        delete[] arr;
    }

public:
    HashMap()
    {
        capacity = 10;
        currentElements = 0;
        hashArray = new HashItem<v>[capacity];
    }

    HashMap(int const cap)
    {
        currentElements = 0;
        if (cap <= 1)
        {
            cout << "Capacity should be greater than 1." << endl;
            return;
        }
        this->capacity = cap;
        hashArray = new HashItem<v>[cap];
    }

    void insert(int const key, v const value)
    {
        if ((double)currentElements / capacity >= loadFactor)
        {
            doubleCapacity();
        }
        int index = key % capacity;
        int i = 1;
        while (hashArray[index].status == 2)
        {
            index = getNextCandidateIndex(key, i++);
        }

        hashArray[index].key = key;
        hashArray[index].value = value;
        hashArray[index].status = 2;
        currentElements++;
    }

    bool deleteKey(int const key)
    {
        int index = key % capacity;
        int i = 1;
        while (hashArray[index].status != 0 && hashArray[index].key != key)
        {
            index = getNextCandidateIndex(key, i++);
        }

        if (hashArray[index].status == 2 && hashArray[index].key == key)
        {
            hashArray[index].status = 1; // Mark as deleted
            return true;
        }

        return false;
    }

    v* get(int const key) {
        int index = key % capacity;
        int i = 1;
        int originalIndex = index;

        while (hashArray[index].status != 0 && hashArray[index].key != key)
        {
            index = getNextCandidateIndex(key, i++);
            if (index == originalIndex) {
             
                return nullptr;
            }
        }

        if (hashArray[index].status == 2 && hashArray[index].key == key) {
            return &(hashArray[index].value);
        }

        return nullptr;
    }


    ~HashMap()
    {
        delete[] hashArray;
    }
};

template <class v>
class QHashMap : public HashMap<v>
{
public:
    QHashMap() : HashMap<v>() {}

    QHashMap(int const capacity) : HashMap<v>(capacity) {}

private:
    int getNextCandidateIndex(int key, int i)
    {
        return (key + i * i) % this->capacity;
    }
};

template <class v>
class DHashMap : public HashMap<v>
{
public:
    DHashMap() : HashMap<v>() {}

    DHashMap(int const capacity) : HashMap<v>(capacity)
    {
        if (capacity <= 1)
        {
            std::cerr << "Capacity should be greater than 1." << std::endl;
            return;
        }
    }

private:
    int getNextCandidateIndex(int key, int i)
    {
        int fv = key % this->capacity;
        const int prime = 7; // Any prime number could be used here
        int sv = (prime - (key % prime));
        return (fv + i * sv) % this->capacity;
    }
};

int main() {
    
    HashMap<string> map;
    map.insert(20, "laiba");
    map.insert(50, "meena");
    map.insert(60, "laiba");
    map.insert(70, "laiba");
    map.insert(80, "laiba");
    map.insert(100, "sapna");
    cout << *map.get(100);
    map.deleteKey(100);
    assert(map.get(100) == nullptr);
    QHashMap<string> Qmap;
    Qmap.insert(20, "laiba");
    Qmap.insert(50, "meena");
    Qmap.insert(60, "laiba");
    Qmap.insert(70, "laiba");
    Qmap.insert(80, "laiba");
    Qmap.insert(100, "sapna");
    cout << *Qmap.get(100);
    Qmap.deleteKey(100);
    assert(Qmap.get(100) == nullptr);
    QHashMap<string> Dmap;
    Dmap.insert(20, "laiba");
    Dmap.insert(50, "meena");
    Dmap.insert(60, "laiba");
    Dmap.insert(70, "laiba");
    Dmap.insert(80, "laiba");
    Dmap.insert(100, "sapna");
    cout << *Dmap.get(100);
    Dmap.deleteKey(100);
    assert(Dmap.get(100) == nullptr);
    return 0;
}