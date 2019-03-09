#include<bits/stdc++.h>
using namespace std;
struct item
{
    int start, end;
};
bool cmp(item a, item b)
{
    return a.end < b.end;
}
int max_activity(item arr[], int n)
{
    int j = 0, total = 0;
    for (int i = 1;i < n;i++)
    {
        if (arr[i].start >= arr[j].end)
        {
            j = i;
            total++;
        }
    }
    return total + 1;
}
int main()
{
    item arr[] = {{0,5},{7,15},{8,10},{20,30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, cmp);
    cout << max_activity(arr, n);
}
