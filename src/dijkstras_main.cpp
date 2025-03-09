#include "dijkstras.h"

int main() 
{
    Graph g;
    file_to_graph("src/small.txt", g);
    vector<int> prev;
    vector<int> distances = dijkstra_shortest_path(g, 0, prev);
    for (int i = 0; i < g.numVertices; ++i)
        print_path(extract_shortest_path(prev, i), distances[i]);
}