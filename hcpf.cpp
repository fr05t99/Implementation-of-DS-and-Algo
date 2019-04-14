#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    if (v.size() > 1)
    {
        int g = __gcd(v[0], v[1]);
    for (int i = 2;i < v.size();i++)
    {
        g = __gcd(g, v[i]);
    }
    cout << g;
    }
    else
    {
        cout << v[0];
    }
    return 0;
}
