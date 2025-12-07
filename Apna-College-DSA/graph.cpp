#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
class Graph
{
    int size;
    list<int> *l;
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
};

class INGraph
{
    // int size;
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

}
;
int main()
{
    INGraph usa ;
    usa.addweightedEdge("Seattle","Denver",1316);
    usa.addweightedEdge("Seattle","San Fran",808);
    usa.addweightedEdge("San Fran","Las Vegas",568);
    usa.addweightedEdge("Las Vegas","Denver",748);
    usa.addweightedEdge("San Fran","Los Angeles",388);
    usa.addweightedEdge("Los Angeles","Las Vegas",269);

    usa.printCities();
    return 0;
}