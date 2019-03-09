#include<bits/stdc++.h>
using namespace std;
bool canBeDone(vector<int> &C, int d, int c)
{
    int cnt = 1; int pos_of_cow = C[0];
    auto i = C.begin();
    //i++;
    while (i != C.end())
    {
        if ((*i - pos_of_cow) >= d)
        {
            cnt++;
            pos_of_cow = *i;
        }
        i++;
        if (cnt == c)
        {
            return true;
        }
    }
    return false;
}
int sol(int A, int B, vector<int> &C) {
    int s = 1, e = A;
    int d_max = INT_MIN;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (canBeDone(C, mid, B) && d_max < mid)
        {
            d_max = mid;
        }
        if (canBeDone(C,mid,B))
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return d_max;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        int n, c, a, ma = INT_MIN, mi = INT_MAX;
        cin >> n >> c;
        for (int i = 0;i < n;i++)
        {
            cin >> a;
            if (ma < a)
            {
                ma = a;
            }
            if (mi > a)
            {
                mi = a;
            }
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        cout << sol(ma - mi, c, v)<<endl;
    }
}
