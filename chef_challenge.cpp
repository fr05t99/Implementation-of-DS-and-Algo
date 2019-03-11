#include<bits/stdc++.h>
#define ll long long
using namespace std;
int helper3(vector<int> &v, int median, int k)
{
    int lmedian = 0, rmedian = 0, i = median - 1, j = median + 1;
    if (median >= 0)
    {
        lmedian = v[median] - 1;
    }
    if (median < v.size())
    {
        rmedian = v[median] + 1;
    }
    int c = 1;
    int steps = 0;
    while (c != k)
    {
        if (i >= 0 && j < v.size())
        {
            if (lmedian - v[i] > v[j] - rmedian)
            {
                c++;
                steps += (v[j] - rmedian);
                rmedian++;
                j++;
            }
            else
            {
                c++;
                steps += (lmedian - v[i]);
                lmedian--;
                i--;
            }
        }
        else if (i >= 0)
        {
            c++;
                steps += (lmedian - v[i]);
                lmedian--;
                i--;
        }
        else if (j < v.size())
        {
            c++;
                steps += (v[j] - rmedian);
                rmedian++;
                j++;
        }
    }
    return steps;
}
int helper2(vector<int> &v, int k)
{
    int mi = INT_MAX;
    for (int i = 0;i < v.size();i++)
    {
        mi = min(helper3(v, i, k), mi);
    }
    return mi;
}
int helper(int n, int k)
{
    bool d = false;
    unordered_map<int, vector<int> > m;
    for (int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        if (m.count(a) == 0)
        {
            vector<int> v;
            v.push_back(i);
            m.insert(make_pair(a, v));
        }
        else
        {
            m[a].push_back(i);
            if (m[a].size() >= k)
            {
                d = true;
            }
        }
    }
    if (!d)
    {
        return -1;
    }
    int mi = INT_MAX;
    for (auto i = m.begin();i != m.end();i++)
    {
        if (i->second.size() >= k)
        {
            mi = min(mi, helper2(i->second, k));
        }
    }
    return mi;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        cout << helper(n, k) << endl;
    }
}
