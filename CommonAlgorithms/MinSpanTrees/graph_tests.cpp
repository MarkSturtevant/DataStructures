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
    cout << 1 << " | " << g.add_vertex(3) << endl;
    cout << 1 << " | " << g.contains_vertex(1) << endl;
    cout << 0 << " | " << g.contains_vertex(4) << endl;
    cout << 4 << " | " << g.vertex_count() << endl;
    cout << "Adding first edges" << endl;
    cout << 1 << " | " << g.add_edge(0, 1, 5.0) << endl;
    cout << 1 << " | " << g.add_edge(1, 3, 4.0) << endl;
    cout << 1 << " | " << g.add_edge(1, 2, 3.0) << endl;
    cout << 1 << " | " << g.add_edge(2, 3, 2.0) << endl;
    cout << 4 << " | " << g.edge_count() << endl;
    cout << "Testing Equalities" << endl;
    cout << 1 << " | " << g.contains_edge(1, 0) << endl;
    cout << 1 << " | " << g.contains_edge(1, 3) << endl;
    cout << 0 << " | " << g.contains_edge(2, 0) << endl;
    cout << 5.0 << " | " << g.cost(0, 1) << endl;
    cout << 3.0 << " | " << g.cost(2, 1) << endl;
    cout << INFINITY << " | " << g.cost(3, 0) << endl;
    cout << "Removing an edge" << endl;
    cout << 1 << " | " << g.remove_edge(2, 1) << endl;
    cout << 0 << " | " << g.remove_edge(0, 3) << endl;
    cout << 0 << " | " << g.contains_edge(2, 1) << endl;
    cout << 3 << " | " << g.edge_count() << endl;
    cout << "Removing a vertex" << endl;
    cout << 1 << " | " << g.remove_vertex(1) << endl;
    cout << 0 << " | " << g.remove_vertex(4) << endl;
    cout << 0 << " | " << g.contains_vertex(1) << endl;
    cout << 0 << " | " << g.contains_edge(1, 3) << endl;
    cout << 0 << " | " << g.contains_edge(3, 1) << endl;
    cout << 0 << " | " << g.contains_edge(2, 1) << endl;
    cout << 0 << " | " << g.contains_edge(0, 1) << endl;
    cout << 1 << " | " << g.contains_edge(2, 3) << endl;
    cout << 3 << " | " << g.vertex_count() << endl;
    cout << 1 << " | " << g.edge_count() << endl;
    cout << INFINITY << " | " << g.cost(3, 1) << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;

    Graph g1;
    g1.add_vertex(1);
    g1.add_vertex(2);
    g1.add_vertex(3);
    g1.add_edge(1, 2, 1);
    Graph g2(g1);
    g2.add_edge(3, 1, 3);

    cout << 1 << " | " << g1.contains_edge(2, 1) << endl;
    cout << 0 << " | " << g1.contains_edge(3, 1) << endl;
    cout << 1 << " | " << g2.contains_edge(2, 1) << endl;
    cout << 1 << " | " << g2.contains_edge(3, 1) << endl;

    g1 = g2;
    g1.remove_edge(3, 1);

    cout << 1 << " | " << g1.contains_edge(2, 1) << endl;
    cout << 0 << " | " << g1.contains_edge(3, 1) << endl;
    cout << 1 << " | " << g2.contains_edge(2, 1) << endl;
    cout << 1 << " | " << g2.contains_edge(3, 1) << endl;

    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;


    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;

    std::cout << "make an empty graph" << std::endl;
    Graph G;

    std::cout << "add vertices" << std::endl;
    for (size_t n = 1; n <= 7; n++) {
        G.add_vertex(n);
    }

    std::cout << "add undirected edges" << std::endl;
    G.add_edge(1,2,5);  // 1 --{5} 2; (edge between 1 and 2 with weight 5)
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

    std::cout << "compute a minimum spanning tree" <<std::endl;
    std::list<std::pair<size_t,size_t>> mst = G.prim();

    std::cout << "print minimum spanning tree" <<std::endl;
    double tree_cost = 0;
    for (const std::pair<size_t,size_t>& edge : mst) {
        std::cout << edge.first << " --{"<<G.cost(edge.first,edge.second)<<"} " << edge.second << ";" << std::endl;
        tree_cost += G.cost(edge.first,edge.second);
    }
    std::cout << "tree cost = " << tree_cost <<std::endl;

    std::cout << "distances" << G.distance(2) << " " << G.distance(9);




    return 0;
}
