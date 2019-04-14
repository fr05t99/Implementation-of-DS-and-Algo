#include<bits/stdc++.h>
using namespace std;
long long ans;
long long n;
template<typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, int> > > m;
    void addEdge(T u, T v, int dist, bool bidir = true)
    {
        m[u].push_back(make_pair(v, dist));
        if (bidir)
        {
            m[v].push_back(make_pair(u, dist));
        }
    }
    void printAdj()
    {
        for (auto i : m)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }
    void dfsHelper(int node, unordered_map<int, bool> &visited, vector<int> &countArray)
    {
        visited[node] = true;
        int c = 0;
        for (auto i : m[node])
        {
            if (visited[i.first] == false)
            {
                dfsHelper(i.first, visited, countArray);
                countArray[node] += countArray[i.first];
                ans += min(countArray[i.first], (int)n - countArray[i.first]) * 2ll * i.second;
            }
        }

    }
    void dfs(vector<int> &countArray)
    {
        unordered_map<int, bool> visited;
        for (auto i : m)
        {
            visited[i.first] = false;
        }
        int src = 1;
        dfsHelper(src, visited, countArray);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int tno = 1;
    while (tno <= t)
    {
        ans = 0;
        Graph<int> g;
        //int n;
        cin >> n;
        for (int i = 0;i < n - 1;i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            g.addEdge(x, y, z);
        }
        vector<int> countArray(n + 1, 1);
        g.dfs(countArray);
        cout << "Case #" << tno << ": " << ans << endl;
        tno++;
    }
}
