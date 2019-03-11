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
    bool isCycle(T src)
    {
        map<T, bool> visited;
        map<T, T> parent;
        parent[src] = src;
        visited[src] = true;
        queue<T> q;
        q.push(src);
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (auto i : adjList[node])
            {
                if (visited[i] == true && parent[node] != i)
                {
                    return true;
                }
                else if (!visited[i])
                {
                    visited[i] = true;
                    parent[i] = node;
                    q.push(i);
                }
            }
        }
        return false;
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g.addEdge(2, 3);   // Comment this line to see no cycle
    cout << g.isCycle(1);
}
