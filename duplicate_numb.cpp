#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int> A;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    int no = A.size() - 1;
    int items = sqrt(n);
    int range = (no / items) + 1;
    vector<int> buckets(range,0);
    for (int i = 0;i < A.size();i++)
    {
        buckets[(A[i] - 1) / items]++;
    }
    int select = range - 1;
    for (int i = 0;i < range - 1;i++)
    {
        if (buckets[i] > items)
        {
            select = i;
            break;
        }
    }
    unordered_map<int, int> m;
    for (int i = 0;i < A.size();i++)
    {
        if ( ((select * items) < A[i]) && (A[i] <= ((select + 1) * items)))
        {
            m[A[i]]++;
            if (m[A[i]] > 1)
                cout << A[i];break;
        }
    }
    cout <<  -1;
}
