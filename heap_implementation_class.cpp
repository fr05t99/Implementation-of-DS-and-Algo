#include<bits/stdc++.h>
using namespace std;
class Heap
{
    vector<int> heapStore;
    bool minHeap;
    bool cmp(int a, int b)
    {
        if (minHeap)
        {
            return a < b;
        }
        else
        {
            return a > b;
        }
    }
     void heapify(int index)
    {
        int left = 2 * index;
        int right = 2 * index + 1;
        int minIndex = index;
        if (left < heapStore.size() && cmp(heapStore[left], heapStore[minIndex]))
        {
            minIndex = left;
        }
        if (right < heapStore.size() && cmp(heapStore[right], heapStore[minIndex]))
        {
            minIndex = right;
        }
        if (minIndex != index)
        {
            swap(heapStore[index], heapStore[minIndex]);
            heapify(minIndex);
        }
    }
public:
    Heap(bool type = true)
    {
        minHeap = type;
        //We are using from index 1 to satisfy (parent = index / 2) property
        heapStore.push_back(-1);
    }
    void push(int x)
    {
        heapStore.push_back(x);
        int index = heapStore.size() - 1;
        int parent = index / 2;
        while (index > 1 && cmp(heapStore[index], heapStore[parent]))
        {
            swap(heapStore[index], heapStore[parent]);
            index = parent;
            parent = parent / 2;
        }
    }
    void show()
    {
        for (int i = 0;i < heapStore.size();i++)
        {
            cout<<heapStore[i] << " ";
        }
        cout << endl;
    }
    bool empty()
    {
        return heapStore.size() == 1;
    }
    int top()
    {
        return heapStore[1];
    }
    void pop()
    {
        int last = heapStore.size() - 1;
        swap(heapStore[1], heapStore[last]);
        heapStore.pop_back();
        heapify(1);
    }
    void shiftUp(int index)
    {
        int parent = index / 2;
        while (index > 1 && cmp(heapStore[index], heapStore[parent]))
        {
            swap(heapStore[index], heapStore[parent]);
            index = parent;
            parent = index / 2;
        }
    }
    void shiftDown(int index)
    {
        int minIndex = index;
        int rightChild = 2 * index + 1;
        int leftChild = 2 * index;
        if (leftChild < heapStore.size() && cmp(heapStore[leftChild], heapStore[minIndex]))
        {
            minIndex = leftChild;
        }
        if (rightChild < heapStore.size() && cmp(heapStore[rightChild], heapStore[minIndex]))
        {
            minIndex = rightChild;
        }
        if (minIndex != index)
        {
            swap(heapStore[minIndex], heapStore[index]);
            shiftDown(minIndex);
        }
    }
    void increaseKey(int new_index, int new_val)
    {
        heapStore[new_index] = new_val;
        if (minHeap)
        {
            shiftDown(new_index);
        }
        else
        {
            shiftUp(new_index);
        }
    }
    void decreaseKey(int new_index, int new_val)
    {
        heapStore[new_index] = new_val;
        if (minHeap)
        {
            shiftUp(new_index);
        }
        else
        {
            shiftDown(new_index);
        }
    }
    bool changeKey(int new_index, int new_val)
    {
        if (new_index >= heapStore.size())
        {
            return false;
        }
        if (heapStore[new_index] > new_val)
        {
            decreaseKey(new_index, new_val);
        }
        else
        {
            increaseKey(new_index, new_val);
        }
        return true;
    }
    bool deleteAtRandom(int index)
    {
        if (index >= heapStore.size())
        {
            return false;
        }
        swap(heapStore[index], heapStore[heapStore.size() - 1]);
        heapStore.pop_back();
        heapify(index);
    }
};
int main()
{
    Heap h;
    h.push(5);
    h.push(20);
    h.push(15);
    h.push(2);
    h.push(4);
    h.push(6);
    h.push(1);
    h.show();
    h.deleteAtRandom(3);
    h.show();
}
