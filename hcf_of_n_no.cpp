#include<iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    gcd(b, a % b);
}
int main()
{
    int n;
    cin >> n;
    int a[n], gc;
    cin >> a[0];
    gc = a[0];
    for (int i = 1;i < n;i++)
    {
        cin >> a[i];
        gc = gcd(gc, a[i]);
    }
    cout<<gc<<endl;
}
