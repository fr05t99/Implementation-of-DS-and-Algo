#include<bits/stdc++.h>
using namespace std;
class Test
{
public:
    string name;
    int a, b;
    Test()
    {

    }
    Test(string g, int x, int y)
    {
        name = g;
        a = x;
        b = y;
    }
};
int main()
{
    unordered_map<string, Test> m;
    Test t("Name", 5, 6);
    m[t.name] = t;
    cout << m["Name"].a << endl;
}
