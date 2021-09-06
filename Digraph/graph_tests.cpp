#include "graph.h"

#include <iostream>

using std::cout, std::endl;

int main() {
    Graph g;

    cout << "First Tests" << endl;
    cout << 0 << " | " << g.edge_count() << endl;
    cout << 0 << " | " << g.vertex_count() << endl;
    cout << "Adding first Nodes" << endl;
    cout << 1 << " | " << g.add_vertex(0) << endl;
    cout << 1 << " | " << g.add_vertex(1) << endl;
    cout << 1 << " | " << g.add_vertex(2) << endl;
    cout << 1 << " | " << g.contains_vertex(1) << endl;
    cout << 0 << " | " << g.contains_vertex(4) << endl;
    cout << 3 << " | " << g.vertex_count() << endl;
    cout << "Adding first edges" << endl;
    cout << 1 << " | " << g.add_edge(0, 1, 5.0) << endl;
    cout << 1 << " | " << g.add_edge(0, 2, 2.5) << endl;
    cout << 1 << " | " << g.add_edge(1, 0, 10.0) << endl;
    cout << 1 << " | " << g.add_edge(2, 1, 3.5) << endl;
    cout << 1 << " | " << g.add_edge(2, 0, 1.1) << endl;
    cout << 0 << " | " << g.add_edge(0, 2, 3.5) << endl;
    cout << 5 << " | " << g.edge_count() << endl;
    cout << "Testing Equalities" << endl;
    cout << 1 << " | " << g.contains_edge(0, 2) << endl;
    cout << 1 << " | " << g.contains_edge(1, 0) << endl;
    cout << 0 << " | " << g.contains_edge(1, 2) << endl;
    cout << 5.0 << " | " << g.cost(0, 1) << endl;
    cout << 2.5 << " | " << g.cost(0, 2) << endl;
    cout << INFINITY << " | " << g.cost(1, 2) << endl;
    cout << "Removing an edge" << endl;
    cout << 1 << " | " << g.remove_edge(2, 0) << endl;
    cout << 0 << " | " << g.remove_edge(1, 2) << endl;
    cout << 0 << " | " << g.contains_edge(2, 0) << endl;
    cout << 4 << " | " << g.edge_count() << endl;
    cout << "Removing a vertex" << endl;
    cout << 1 << " | " << g.remove_vertex(0) << endl;
    cout << 0 << " | " << g.remove_vertex(3) << endl;
    cout << 0 << " | " << g.contains_vertex(0) << endl;
    cout << 0 << " | " << g.contains_edge(0, 2) << endl;
    cout << 0 << " | " << g.contains_edge(1, 0) << endl;
    cout << 0 << " | " << g.contains_edge(2, 0) << endl;
    cout << 0 << " | " << g.contains_edge(0, 1) << endl;
    cout << 1 << " | " << g.contains_edge(2, 1) << endl;
    cout << 2 << " | " << g.vertex_count() << endl;
    cout << 1 << " | " << g.edge_count() << endl;
    cout << INFINITY << " | " << g.cost(0, 2) << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;

    Graph g1;
    g1.add_vertex(1);
    g1.add_vertex(2);
    g1.add_edge(1, 2, 1);
    Graph g2(g1);
    g2.add_edge(2, 1, 3);

    cout << 0 << " | " << g1.contains_edge(2, 1) << endl;
    cout << 1 << " | " << g2.contains_edge(2, 1) << endl;
    cout << 1 << " | " << g1.contains_edge(1, 2) << endl;
    cout << 1 << " | " << g2.contains_edge(1, 2) << endl;

    g1 = g2;
    g1.remove_edge(1, 2);

    cout << 1 << " | " << g1.contains_edge(2, 1) << endl;
    cout << 1 << " | " << g2.contains_edge(2, 1) << endl;
    cout << 0 << " | " << g1.contains_edge(1, 2) << endl;
    cout << 1 << " | " << g2.contains_edge(1, 2) << endl;

    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;

    Graph graph;
    graph.add_vertex(0);
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_vertex(4);
    graph.add_vertex(5);
    graph.add_vertex(6);
    graph.add_vertex(7);

    graph.add_edge(0, 3, 9);
    graph.add_edge(0, 1, 1);
    graph.add_edge(1, 0, 2);
    graph.add_edge(1, 5, 4);
    graph.add_edge(5, 1, 3);
    graph.add_edge(5, 0, 6);
    graph.add_edge(0, 5, 8);
    graph.add_edge(5, 4, 1);
    graph.add_edge(4, 2, 1);
    graph.add_edge(1, 2, 7);
    graph.add_edge(2, 3, 1);
    graph.add_edge(6, 7, 3);
    graph.add_edge(7, 6, 2);

    graph.dijkstra(0);

    for (size_t i = 0; i <= 8; ++i) {
        cout << "Dikstras for i = " << i << " (distance: " << graph.distance(i) << ")" << endl;
        graph.print_shortest_path(i);
    }

    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;

    std::cout << "make an empty digraph" << std::endl;
    Graph G;

    std::cout << "add vertices" << std::endl;
    for (size_t n = 1; n <= 7; n++) {
        G.add_vertex(n);
    }

    std::cout << "add directed edges" << std::endl;
    G.add_edge(1,2,5);  // 1 ->{5} 2; (edge from 1 to 2 with weight 5)
    G.add_edge(1,3,3);
    G.add_edge(2,3,2);
    G.add_edge(2,5,3);
    G.add_edge(2,7,1);
    G.add_edge(3,4,7);
    G.add_edge(3,5,7);
    G.add_edge(4,1,2);
    G.add_edge(4,6,6);
    G.add_edge(5,4,2);
    G.add_edge(5,6,1);
    G.add_edge(7,5,1);

    std::cout << "G has " << G.vertex_count() << " vertices" << std::endl;
    std::cout << "G has " << G.edge_count() << " edges" << std::endl;

    std::cout << "compute shortest path from 2" <<std::endl;
    G.dijkstra(2);

    std::cout << "print shortest paths" <<std::endl;
    for (size_t n = 1; n <= 7; n++) {
        std::cout << "shortest path from 2 to " << n << std::endl;
        std::cout << "  ";
        G.print_shortest_path(n);
    }



    return 0;
}
