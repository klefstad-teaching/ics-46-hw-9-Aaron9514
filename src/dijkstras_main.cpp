#include "dijkstras.h"

int main() 
{
    Graph g;
    file_to_graph("src/largest.txt", g);
    vector<int> prev;
    vector<int> distances = dijkstra_shortest_path(g, 0, prev);
    for (int i = 0; i < g.numVertices; ++i) {
        for (auto v : extract_shortest_path(distances, prev, i))
            cout << v << " ";
        cout << endl;
        cout << "The total cost is " << distances[i] << endl;
    }
}