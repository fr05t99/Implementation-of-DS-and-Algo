#include<iostream>
using namespace std;
int main() {
  int t = 0;
  cin>>t;
  while (t--)
  {
    int c1, c2, c3, c4;
    int n, m;
    int min1 = 0, min2 = 0;
    int r[1000], c[1000];
    cin>>c1>>c2>>c3>>c4;
    cin>>n>>m;
    for (int i = 0;i < n;i++)
    {
      cin>>r[i];
      min1 += min(r[i] * c1, c2);
    }
    if (min1 > c3)
    {
      min1 = c3;
    }
    for (int i = 0;i < m;i++)
    {
      cin>>c[i];
      min2 += min(c[i] * c1, c2);
    }
    if (min2 > c3)
    {
      min2 = c3;
    }
    if ((min1 + min2) < c4)
    {
      cout<<min1 + min2<<endl;
    }
    else
    {
      cout<<c4<<endl;
    }
  }
	return 0;
}
