#include<bits/stdc++.h>
using namespace std;
//Wrong
template<typename T>
class Graph
{
    map<T, list<T> > adjList;
public:
    map<T, int> visited;
    Graph()
    {

    }
    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto entry : i.second)
            {
                cout << entry << ", ";
            }
            cout << endl;
        }
    }
    bool isBipartite(T s)
    {
        queue<T> q;
        for (auto i : adjList)
        {
            visited[i.first] = -1;
        }
        q.push(s);
        visited[s] = 0;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (auto i : adjList[node])
            {
                if (visited[i] == -1)
                {
                    visited[i] = 1 - visited[node];
                    q.push(i);
                }
                else if (visited[i] == visited[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Graph<int> g;
        int n, e;
        cin >> n >> e;
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            g.addEdge(a, b);
        }
        if (g.isBipartite(1))
        {
            auto i = g.visited.begin();
            int count = 0;
            while (i != g.visited.end())
            {
                if (i->second == 0) count++;
                i++;
            }
            cout << count << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}


