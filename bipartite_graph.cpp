#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph
{
    map<T, list<T> > adjList;
public:
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
        map<T, int> visited;
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
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    //g.addEdge(0, 3); // Uncomment it for not bipartite
    cout << g.isBipartite(0);
}

