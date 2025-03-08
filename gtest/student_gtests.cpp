#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

Graph fill_graph(string file_name)
{
    Graph g;
    ifstream in(file_name);
    in >> g;
    in.close();
    return g;
}
TEST(test_dijkstras, test_short_path_distances_0) 
{
    vector<int> result = {0, 3, 6, 1};
    vector<int> prev;
    Graph g = fill_graph("src/small.txt");
    EXPECT_EQ(dijkstra_shortest_path(g, 0, prev), result);
}

TEST(test_dijkstras, test_short_path_distances_1) 
{
    vector<int> result = {5, 0, 3, 6};
    vector<int> prev;
    Graph g = fill_graph("src/small.txt");
    EXPECT_EQ(dijkstra_shortest_path(g, 1, prev), result);
}

TEST(test_dijkstras, test_short_path_distances_2) 
{
    vector<int> result = {11, 10, 0, 8};
    vector<int> prev;
    Graph g = fill_graph("src/small.txt");
    EXPECT_EQ(dijkstra_shortest_path(g, 2, prev), result);
}

TEST(test_dijkstras, test_short_path_distances_3) 
{
    vector<int> result = {3, 2, 5, 0};
    vector<int> prev;
    Graph g = fill_graph("src/small.txt");
    EXPECT_EQ(dijkstra_shortest_path(g, 3, prev), result);
}

TEST(test_dijkstras, test_previous_0_small)
{
    vector<int> result = {-1, 3, 1, 0};
    vector<int> prev;
    Graph g = fill_graph("src/small.txt");
    dijkstra_shortest_path(g, 0, prev);
    EXPECT_EQ(prev, result);
}

TEST(test_dijkstras, test_previous_0_medium)
{
    vector<int> result = {-1, 0, 5, 2, 5, 0};
    vector<int> prev;
    Graph g = fill_graph("src/medium.txt");
    dijkstra_shortest_path(g, 0, prev);
    EXPECT_EQ(prev, result);
}

TEST(test_dijkstras, test_previous_1_small)
{
    vector<int> result = {1, -1, 1, 0};
    vector<int> prev;
    Graph g = fill_graph("src/small.txt");
    dijkstra_shortest_path(g, 1, prev);
    EXPECT_EQ(prev, result);
}

TEST(test_dijkstras, test_previous_1_medium)
{
    vector<int> result = {4, -1, 1, 2, 3, 3};
    vector<int> prev;
    Graph g = fill_graph("src/medium.txt");
    dijkstra_shortest_path(g, 1, prev);
    EXPECT_EQ(prev, result);
}
