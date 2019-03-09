#include<iostream>
//Correct
#include<algorithm>
using namespace std;
int no, mo;
bool b_search(int *a,int x, int m)
{
    int s = 0, e = m - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (*(a + mid) == x)
        {
            return true;
        }
        else if (*(a + mid) < x)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return false;
}
int main()
{
    int n, m, x;
    cin >> n >> m;
    no = n;
    mo = m;
    int a[n][m], row_no = -1;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> x;
    int d = 0;
    for (int i = 0;i < n;i++)
    {
        if (binary_search(*(a + i),*(a + i) + m,x))
            {
                d = 1;
                break;
            }
    }
    cout << d << endl;
}
