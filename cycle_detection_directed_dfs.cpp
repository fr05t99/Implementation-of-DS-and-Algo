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
    bool isCycleHelper(T node, map<T, bool> &visited, map<T, bool> &inStack)
    {
        visited[node] = true;
        inStack[node] = true;
        for (auto i : adjList[node])
        {
            if ((!visited[i] && isCycleHelper(i, visited, inStack)) || inStack[i])
            {
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }
    bool isCycle()
    {
        map<T, bool> visited;
        map<T, bool> inStack;
        for (auto i : adjList)
        {
            if (!visited[i.first])
            {
                bool cyclePresent = isCycleHelper(i.first, visited, inStack);
                if (cyclePresent)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 2, false);
    g.addEdge(0, 1, false);
    g.addEdge(2, 3, false);
    g.addEdge(2, 4, false);
    g.addEdge(3, 0, false); // Comment this for no cycle
    g.addEdge(4, 5, false);
    g.addEdge(1, 5, false);
    cout << g.isCycle();
}
