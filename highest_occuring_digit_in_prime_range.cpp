#include<iostream>
using namespace std;
int main()
{
    int m1, m2;
    cin>>m1>>m2;
    int n = max(m1, m2);
    int m = min(m1, m2);
    int sieve[n + 1] = {0};
    for (int i = 2;i <= n;i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i + i;j <= n;j += i)
            {
                sieve[j] = 1;
            }
        }
    }
    int count[10] = {0};
    for (int i = max(2,m);i <= n;i++)
    {
        if (sieve[i] == 0)
        {
            int h = i;
            while (h != 0)
            {
                int r = h % 10;
                h = h / 10;
                count[r]++;
            }
        }
    }
    for (int i = 1;i < 10;i++)
    {
        cout<<i<<" occured "<<count[i]<<" times."<<endl;
    }
}
