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
};
int main()
{
    Graph<string> g;
    g.addEdge("Modi", "Rahul", true);
    g.addEdge("Rahul", "Yogi", false);
    g.addEdge("Yogi", "Pope", true);
    string t = "Modi";
    g.bfs(t);
}
