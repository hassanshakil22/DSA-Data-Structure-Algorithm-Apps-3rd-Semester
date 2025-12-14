#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;
class Graph
{
    int size;
    list<int> *l; // arr with each element has list of integers ( adjacency list )
public:
    Graph(int size)
    {
        this->size = size;
        l = new list<int>[size];
    }
    void addEdge(int v1, int v2)
    {
        l[v1].push_back(v2);
        l[v2].push_back(v1);
    }

    void BFSTraversal()
    {
        queue<int> Q;
        vector<bool> vis(size, false);

        Q.push(0);
        vis[0] = true;

        while (Q.size() > 0)
        {
            int u = Q.front();
            Q.pop();

            cout << " " << u;
            for (int v : l[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl;
    }

    void DFSTraversal()
    {
        vector<bool> vis(size, false);
        DFS(0, vis);
    }
    void DFS(int u, vector<bool> vis)
    {
        cout << u << " ";
        vis[u] = true;
        for (int v : l[u])
        {
            if (!vis[v])
                DFS(v, vis);
        }
    }

    void TopologicalSort()
    {
        stack<int> s;
        vector<bool> vis(size, false);
        for (int i = 0; i < size; i++)
        {
            if (!vis[i])
                Topo(s, i, vis);
        }
        cout << "Final sorted : ";
        while (s.size() > 0)
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
    void Topo(stack<int> &s, int u, vector<bool> &vis)
    {
        vis[u] = true;
        for (int v : l[u])
        {
            if (!vis[v])
                Topo(s, v, vis);
        }
        s.push(u);
    }

    void KahnTopoLogical()
    {
        queue<int> q;
        vector<int> indeg(size, 0);
        vector<int> res;
        // calculate indegree
        for (int u = 0; u < size; u++)
        {
            for (int v : l[u])
                indeg[v]++;
        }
        // push all 0 indegree ones in queue
        for (int u = 0; u < size; u++)
        {
            if (indeg[u] == 0)
                q.push(u);
        }
        // check indegrees and pop
        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (int v : l[curr])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                    q.push(v);
            }
        }
        // print the sorted
        for (int i : res)
        {
            cout << i << " ";
        }
    }
};

class INGraph
{
    int size;
    unordered_map<string, unordered_map<string, int>> cities;

public:
    INGraph()
    {
        // this->size= size; 
    }
    void addweightedEdge(string city1, string city2, int wieght)
    {
        cities[city1].insert({city2, wieght});
        cities[city2].insert({city1, wieght});
    }

    void printCities()
    {
        for (auto city : cities)
        {
            cout << "City :" << city.first << ": ";
            for (auto adj : city.second)
            {
                cout << " Adjacent City  :" << adj.first << " Distance : " << adj.second;
            }
            cout << endl;
        }
    }
};
int main()
{

    Graph g = Graph(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.BFSTraversal();
    g.DFSTraversal();
    g.TopologicalSort();
    cout << endl;
    g.KahnTopoLogical();

    // INGraph usa;
    // usa.addweightedEdge("Seattle", "Denver", 1316);
    // usa.addweightedEdge("Seattle", "San Fran", 808);
    // usa.addweightedEdge("San Fran", "Las Vegas", 568);
    // usa.addweightedEdge("Las Vegas", "Denver", 748);
    // usa.addweightedEdge("San Fran", "Los Angeles", 388);
    // usa.addweightedEdge("Los Angeles", "Las Vegas", 269);

    // usa.printCities();
    return 0;
}