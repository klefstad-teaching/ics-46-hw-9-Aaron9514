#include "dijkstras.h"

using Node = pair<int, int>;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    vector<bool> visited(G.numVertices, false);
    vector<int> distances(G.numVertices, INF);
    previous.resize(G.numVertices, -1);

    priority_queue<Node, vector<Node>,  // Node is made of a vertex and weight
                greater<>> minHeap;

    distances[source] = 0;
    minHeap.push({0, source});

    while (!minHeap.empty()) {
        Node node = minHeap.top();
        minHeap.pop();
        if (!visited[node.second]) {
            visited[node.second] = true;
            for (Edge e : G[node.second]) {
                int nweight = distances[node.second] + e.weight; // New calculated weight
                if (!visited[e.dst] && nweight < distances[e.dst]) {
                    minHeap.push({nweight, e.dst}); 
                    distances[e.dst] = nweight;
                    previous[e.dst] = node.second;
                }
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination)
{
    stack<int> path;
    path.push(destination);
    for (int cur = previous[destination]; cur != -1; cur = previous[cur])
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