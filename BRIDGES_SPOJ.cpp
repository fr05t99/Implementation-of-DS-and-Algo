#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> t1, t2;
        for (int i = 0;i < n;i++)
        {
            int a;
            cin >> a;
            t1.push_back(a);
        }
        for (int i = 0;i < n;i++)
        {
            int a;
            cin >> a;
            t2.push_back(a);
        }
        vector<pair<int, int> > v;
        for (int i = 0;i < n;i++)
        {
            v.push_back(pair<int, int>(t1[i], t2[i]));
        }
        sort(v.begin(), v.end());
        vector<int> dp(n, 1);
        int m = 1;
        for (int i = 1;i < n;i++)
        {
            for (int j = 0;j < i;j++)
            {
                if (v[j].second <= v[i].second)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            m = max(m, dp[i]);
        }
        cout << m << endl;
    }
}
