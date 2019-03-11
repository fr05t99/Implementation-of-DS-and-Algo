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
        unordered_map<char, int> m;
        for (int i = 0;i < n;i++)
        {
            string s;
            cin >> s;
            unordered_set<char> se;
            for (int j = 0;j < s.length();j++)
            {
                se.insert(s[j]);
            }
            for (auto j = se.begin();j != se.end();j++)
            {
                if (m.count(*j))
                {
                    m[*j]++;
                }
                else
                {
                    m.insert(make_pair(*j, 1));
                }
            }
        }
        int count = 0;
        for (auto i = m.begin();i != m.end();i++)
        {
            if (i -> second >= n)
            {
                count++;
            }
        }
        cout << count << endl;
    }
}
