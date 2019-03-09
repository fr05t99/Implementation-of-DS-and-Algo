#include<bits/stdc++.h>
using namespace std;
class BadNeighbors
{
public:
    int maxDonations(vector<int> arr)
    {

    }
};
int main()
{
    BadNeighbors o;
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << o.maxDonations(arr);
}
