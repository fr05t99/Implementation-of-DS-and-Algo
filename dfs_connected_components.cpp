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
    void bfs(T src)
    {
        map<T, bool> visited;
        queue<T> q;
        visited[src] = true;
        q.push(src);
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (auto i : adjList[node])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    void dfsHelper(T node, map<T, bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";
        for (auto i : adjList[node])
        {
            if (!visited[i])
            {
                dfsHelper(i, visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        int component = 1;
        dfsHelper(src, visited);
        cout << endl;
        for (auto i : adjList)
        {
            if (!visited[i.first])
            {
                dfsHelper(i.first, visited);
                cout << endl;
                component++;
            }
        }
        cout << "\nNo. Of Components " << component;
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(8, 9);
    g.addEdge(9, 10);
    g.addEdge(11, 12);
    g.dfs(0);
}

