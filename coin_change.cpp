#include<bits/stdc++.h>
using namespace std;
int b_search(int arr[], int n, int cost)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == cost)
        {
            return mid;
        }
        if (cost > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s;
}
int main()
{
    int arr[] = {1,2,5,10,20,50,100};
    int cost = 120;
    int n = sizeof(arr) / sizeof(arr[0]);
    int coins = 0;
    while (cost != 0)
    {
        int r = b_search(arr, n, cost);
        if (arr[r] == cost)
        {
            cost -= arr[r];
            //cout << arr[r];
            coins++;
        }
        else
        {
            cost -= arr[r - 1];
            //cout << arr[r - 1];
            coins++;
        }
    }
    cout << coins ;
}
