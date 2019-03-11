#include<bits/stdc++.h>
using namespace std;
bool solver(vector<long long int> &v, int i, int n)
{
    if (i > n)
    {
        return true;
    }
    bool a = false, b = false;
    if ((2 * i <= n && v[i] > v[2 * i]) || (2 * i > n))
    {
        a = true;
    }
    if ((2 * i + 1 <= n && v[i] > v[2 * i + 1]) || (2 * i + 1 > n))
    {
        b = true;
    }
    return (a && b && solver(v, 2 * i, n) && solver(v, 2 * i + 1, n));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long int> v;
        v.push_back(-1);
        for (int i = 0;i < n;i++)
        {
            long long int a;
            cin >> a;
            v.push_back(a);
        }
        cout << checkHeap(v, n) << endl;
    }
}
