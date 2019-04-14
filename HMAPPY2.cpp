#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, a, b, k;
        cin >> n >> a >> b >> k;
        long long int i = ((a * b) / __gcd(a, b));
        if ((n / a) + (n / b) - (2 * (n / i)) >= k)
        {
            cout << "Win\n";
        }
        else
        {
            cout << "Lose\n";
        }
    }
}
