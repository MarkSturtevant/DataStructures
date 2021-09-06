#ifndef GRAPH_H
#define GRAPH_H

#include "priority_queue.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <list>

using std::vector;

struct Edge {
public:
    size_t target;
    double distance;

    Edge(size_t nextNode, double length) : target(nextNode), distance(length) {}
};

class Node {
public:
    size_t id;
    double primDistance;
    vector<Edge> edges;

    explicit Node(size_t nodeID) : id(nodeID), primDistance(-1), edges() {}
    Node() : id(0), edges() {};

    bool operator==(Node& other) const {
        return other.id == this->id;
    }

    bool containsEdge(size_t target) {
        for (Edge e : edges) {
            if (e.target == target)
                return true;
        }

        return false;
    }

    void push(Edge e) {
        edges.push_back(e);
    }

    void remove(size_t index) {
        edges.erase(edges.begin() + index);
    }
};

struct GreatEdge {
    size_t a, b;
    double length;

    GreatEdge() : a(0), b(0), length(-1) {}
    GreatEdge(size_t a, size_t b, double length) : a(a), b(b), length(length) {}
};

struct EdgeCompare {
    bool operator () (const GreatEdge& n1, const GreatEdge& n2) {
        return n1.length < n2.length;
    }
};

class Graph {
private:
    vector<Node*> nodes;
    size_t numEdges;

    void clearNodes();
    Node* getNode(size_t id) const;
public:
    Graph();
    ~Graph();
    Graph(const Graph& other);
    Graph& operator=(const Graph& other);

    size_t vertex_count() const;
    size_t edge_count() const;

    bool contains_vertex(size_t id) const;
    bool contains_edge(size_t src, size_t dest) const;
    double cost(size_t src, size_t dest) const;

    bool add_vertex(size_t id);
    bool add_edge(size_t src, size_t dest, double weight=1);
    bool remove_vertex(size_t id);
    bool remove_edge(size_t src, size_t dest);

    std::list<std::pair<size_t, size_t>> prim();
    double distance(size_t node);
};

void Graph::clearNodes() {
    if (nodes.empty())
        return;
    while (! nodes.empty()) {
        delete nodes.back();
        nodes.pop_back();
    }
}

Graph::Graph() : nodes(), numEdges(0) {}

Graph::~Graph() {
    clearNodes();
}

Graph::Graph(const Graph &other) : nodes(), numEdges(other.numEdges) {
    for (Node* n : other.nodes) {
        Node* n2 = new Node(n->id);
        n2->edges = n->edges;
        n2->primDistance = n->primDistance;
        nodes.push_back(n2);
    }
}

Graph& Graph::operator=(const Graph &other) {
    if (this == &other)
        return *this;

    clearNodes();
    numEdges = other.numEdges;

    for (Node* n : other.nodes) {
        Node* n2 = new Node(n->id);
        n2->edges = n->edges;
        n2->primDistance = n->primDistance;
        nodes.push_back(n2);
    }

    return *this;
}

Node* Graph::getNode(size_t id) const {
    for (Node* n : nodes)
        if (n->id == id)
            return n;
    return nullptr;
}

size_t Graph::vertex_count() const {
    return nodes.size();
}

size_t Graph::edge_count() const {
    return numEdges;
}

bool Graph::contains_vertex(size_t id) const {
    return getNode(id) != nullptr;
}

bool Graph::contains_edge(size_t src, size_t dest) const {
    Node* n = getNode(src);
    if (n == nullptr)
        return false;
    return n->containsEdge(dest);
}

double Graph::cost(size_t src, size_t dest) const {
    Node* n = getNode(src);
    if (n == nullptr)
        return INFINITY;
    for (Edge e : n->edges)
        if (e.target == dest)
            return e.distance;
    return INFINITY;
}

bool Graph::add_vertex(size_t id) {
    Node* n = getNode(id);
    if (n != nullptr)
        return false;
    nodes.push_back(new Node(id));
    return true;
}

bool Graph::add_edge(size_t src, size_t dest, double weight) {
    Node* n = getNode(src);
    Node* n2 = getNode(dest);
    if (n == nullptr || n2 == nullptr || n->containsEdge(dest))
        return false;

    n->push(Edge(dest, weight));
    n2->push(Edge(src, weight));
    numEdges++;
    return true;
}

bool Graph::remove_vertex(size_t id) {
    Node* n = getNode(id);
    if (n == nullptr)
        return false;

    for (Edge e : n->edges) {
        Node* n2 = getNode(e.target);
        size_t j = 0;
        for (; j < n2->edges.size(); ++j)
            if (n2->edges.at(j).target == id)
                break;
        n2->remove(j);
        numEdges--;
    }

    size_t j = 0;
    for (; j < nodes.size(); ++j)
        if (nodes.at(j)->id == id)
            break;
    nodes.erase(nodes.begin() + j);
    delete n;
    return true;
}

bool Graph::remove_edge(size_t src, size_t dest) {
    Node* n = getNode(src);
    Node* n2 = getNode(dest);
    if (n == nullptr || n2 == nullptr || ! n->containsEdge(dest))
        return false;

    size_t j = 0;
    for (; j < n->edges.size(); ++j)
        if (n->edges.at(j).target == dest)
            break;
    n->edges.erase(n->edges.begin() + j);

    for (j = 0; j < n2->edges.size(); ++j)
        if (n2->edges.at(j).target == src)
            break;
    n2->edges.erase(n2->edges.begin() + j);

    numEdges--;
    return true;
}

std::list<std::pair<size_t, size_t>> Graph::prim() {
    for (Node* n : nodes)
        n->primDistance = INFINITY;
    if (nodes.size() <= 1)
        return std::list<std::pair<size_t, size_t>>();
    Node* start = nodes.at(0);

    vector<Node*> visited;
    visited.push_back(start);
    start->primDistance = 0;
    std::list<std::pair<size_t, size_t>> output;
    PriorityQueue<GreatEdge, vector<GreatEdge>, EdgeCompare> pq;
    for (Edge e : start->edges)
        pq.push(GreatEdge(start->id, e.target, e.distance));

    while (! pq.empty()) {
        GreatEdge next = pq.top();
        pq.pop();

        bool aIn = false, bIn = false;
        for (Node* n : visited) {
            if (n->id == next.a) {
                aIn = true;
                if (bIn)
                    break;
            } else if (n->id == next.b) {
                bIn = true;
                if (aIn)
                    break;
            }
        }
        if (aIn && bIn)
            continue;

        Node* next2 = aIn ? getNode(next.b) : getNode(next.a);
        for (Edge e : next2->edges)
            pq.push(GreatEdge(next2->id, e.target, e.distance));
        visited.push_back(next2);
        output.emplace_back(next.a, next.b);
        next2->primDistance = next.length;
    }
    return output;
}

double Graph::distance(size_t node) {
    Node* n = getNode(node);
    if (n == nullptr)
        return INFINITY;
    return n->primDistance;
}

#endif  // GRAPH_H
