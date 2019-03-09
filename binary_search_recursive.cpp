#include<iostream>
using namespace std;
int binary_s(int a[], int x, int s, int e)
{
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (a[mid] == x)
    {
        return mid;
    }
    else if (a[mid] < x)
    {
        binary_s(a, x, mid + 1, e);
    }
    else
    {
        binary_s(a, x, s, mid - 1);
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    cout << binary_s(a, 2, 0, 4)<<endl;
    cout << binary_s(a, 5, 0, 4)<<endl;
    cout << binary_s(a, 7, 0, 4)<<endl;
}
