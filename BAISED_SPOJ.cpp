#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {

    long long int n;
    cin >> n;
    vector<long long int> v;
    string s;
    for (long long int i = 0;i < n;i++)
    {
        long long int a;
        cin >> s;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    long long int num = 1, diff = 0;
    for (auto i = v.begin();i != v.end();i++)
    {
        diff += (abs(num - (*i)));
        num++;
    }
    cout << diff <<endl;
    }
}
