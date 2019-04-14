#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        //n = n % 100000;
        long long int s = 0, e = n, numb = 0;
        while (s <= e)
        {
            long long int mid = (s + e) / 2;
            long long int sum = (mid * (mid + 1)) / 2;
            if (sum <= n && sum > (numb * (numb + 1)) / 2)
            {
                numb = mid;
            }
            if (sum < n)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        //cout << numb;
        long long int sum = (numb * (numb + 1)) / 2;
        if (sum == n)
        {
            cout << (numb * (numb + 1)) % 100000;
        }
        else
        {
            cout << (numb * (n - sum)) % 100000;
        }
        cout<<endl;
    }
    return 0;
}
