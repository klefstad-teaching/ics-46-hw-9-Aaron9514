#include "dijkstras.h"

using Node = pair<int, int>;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    vector<bool> visited(G.numVertices, false);
    vector<int> distances(G.numVertices, INF);
    previous.resize(G.numVertices, -1);

    priority_queue<Node, vector<Node>,  // Node is made of a vertex and weight
                decltype([](Node a, Node b) {return a.second > b.second;})> minHeap;

    distances[source] = 0;
    minHeap.push({source, 0});

    while (!minHeap.empty()) {
        Node node = minHeap.top();
        minHeap.pop();
        if (!visited[node.first]) {
            visited[node.first] = true;
            for (Edge e : G[node.first]) {
                int nweight = node.second + e.weight; // New calculated weight
                if (nweight < distances[e.dst]) {
                    minHeap.push({e.dst, nweight}); 
                    distances[e.dst] = nweight;
                    previous[e.dst] = node.first;
                }
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int dest)
{
    stack<int> path;
    path.push(dest);
    for (int cur = previous[dest]; cur != -1; cur = previous[cur])
        path.push(cur);
    // convert stack into vector
    vector<int> vec_path;
    while(!path.empty()) {
        vec_path.push_back(path.top());
        path.pop();
    }
    return vec_path;
}

void print_path(const vector<int>& v, int total)
{
    for (auto vertex : v)
        cout << vertex << " ";
    cout <<  endl << "Total cost is " << total << endl;
}