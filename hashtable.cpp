#include<bits/stdc++.h>
using namespace std;
template<typename T>
class node
{
public:
    T value;
    string key;
    node<T> *next;
    node(string k, T v)
    {
        key = k;
        value = v;
    }
    ~node()  // Deleting a linked list, recursive call, if next is not NULL go to next and after finding NULL, delete it -> detail in LL
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};
template<typename T>
class HashTable
{
    int currentSize;
    int totalSize;
    node<T> **buckets;
    void rehash()
    {
        node<T> **oldBuckets = buckets;
        int oldTotalSize = totalSize;
        totalSize = 2 * totalSize;
        currentSize = 0;
        buckets = new node<T>*[totalSize];
        for (int i = 0;i < totalSize;i++)
        {
            buckets[i] = NULL;
        }
        for (int i = 0;i < oldTotalSize;i++)
        {
            node<T> *temp = oldBuckets[i];
            while (temp != NULL)
            {
                insert(temp -> key, temp -> value);
                temp = temp -> next;
            }
            delete oldBuckets[i];
        }
        delete [] oldBuckets;
    }
    int hashFun(string key)
    {
        int L = key.length();
        int ans = 0, p = 1; // 37^0 = 1
        for (int i = 0;i < L;i++)
        {
            ans = (ans + key[L - i - 1] * p) % totalSize;
            p = (p * 37) % totalSize;
        }
        return ans;
    }
public:
    HashTable(int ds = 7)
    {
        currentSize = 0;
        totalSize = ds;
        buckets = new node<T>*[totalSize];
        for (int i = 0;i < totalSize;i++)
        {
            buckets[i] = NULL;
        }
    }
    void insert(string key, T value)
    {
        int i = hashFun(key);
        node<T> *n = new node<T>(key, value);
        n -> next = buckets[i];
        buckets[i] = n;
        currentSize++;
        float loadFactor = (float)(currentSize/totalSize);
        if (loadFactor > 0.7)
        {
            cout << "Load Factor is " << loadFactor << ". Rehashing Now" << endl;
            rehash();
        }
    }
    void show()
    {
        for (int i = 0;i < totalSize;i++)
        {
            cout << i << " -> ";
            node<T> *temp = buckets[i];
            while (temp != NULL)
            {
                cout << temp -> key <<" :: " << temp -> value << ", ";
                temp = temp -> next;
            }
            cout << endl;
        }
    }
    T* search(string key)
    {
        int i = hashFun(key);
        node<T> *temp = buckets[i];
        while (temp != NULL)
        {
            if (temp -> key == key)
            {
                return &(temp -> value);
            }
            temp = temp -> next;
        }
        return NULL;
    }
    void removeKey(string key)
    {
        int i = hashFun(key);
        node<T> *temp = buckets[i];
        node<T> *prev = NULL;
        while (temp != NULL)
        {
            if (temp -> key == key)
            {
                node<T> *te = temp;
                if (prev == NULL)
                {
                    buckets[i] = temp -> next;
                    temp = temp -> next;
                }
                else
                {
                    prev -> next = temp -> next;
                    temp = temp -> next;
                }
                delete te;
            }
            else
            {
                prev = temp;
                temp = temp -> next;
            }
        }
    }
};
int main()
{
    HashTable<int> h;
    h.insert("Mango", 1);
    h.insert("Giraffe", 2);
    h.insert("Mango", 3);
    h.insert("Apple", 3);
    h.insert("Appl", 4);
    h.insert("ghf", 4);
    h.insert("ffkjsk", 6);
    auto n = h.search("Mango");
    if (n)
    {
        cout << *n << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    h.show();
    h.removeKey("Apple");
    cout << endl;
    h.show();
}
