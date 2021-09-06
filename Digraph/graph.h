#ifndef GRAPH_H
#define GRAPH_H

#include "priority_queue.h"
#include <vector>
#include <iostream>
#include <cmath>

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
    double dijDistance;
    vector<Node*> dijPath;
    vector<Edge> edges;
    vector<Edge> edgesReversed;

    Node(size_t nodeID) : id(nodeID), dijDistance(INFINITY), dijPath(), edges(), edgesReversed() {}
    Node() : id(0), dijDistance(INFINITY), dijPath(), edges(), edgesReversed() {};

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

    void push(Edge e, bool towards) {
        if (towards)
            edges.push_back(e);
        else edgesReversed.push_back(e);
    }

    void remove(size_t index, bool towards) {
        if (towards)
            edges.erase(edges.begin() + index);
        else edgesReversed.erase(edgesReversed.begin() + index);
    }
};

struct Path {
public:
    vector<Node*> nodeList;
    Node* lastNode;
    double length;

    Path() : nodeList(), lastNode(nullptr), length(0) {}
};

struct PathCompare {
    bool operator () (const Path& n1, const Path& n2) {
        return n1.length < n2.length;
    }
};

class Graph {
private:
    vector<Node*> nodes;
    size_t numEdges;

    void clearNodes() {
        if (nodes.size() == 0)
            return;
        while (! nodes.empty()) {
            delete nodes.back();
            nodes.pop_back();
        }
    }
    Node* getNode(size_t id) const {
        for (Node* n : nodes)
            if (n->id == id)
                return n;
        return nullptr;
    }
public:
    Graph() : nodes(), numEdges(0) {}
    ~Graph() {
        clearNodes();
    }
    Graph(const Graph& other) : nodes(), numEdges(other.numEdges) {
        for (Node* n : other.nodes) {
            Node* n2 = new Node(n->id);
            n2->edges = n->edges;
            n2->edgesReversed = n->edgesReversed;
            n2->dijDistance = n->dijDistance;
            n2->dijPath = n->dijPath;
            nodes.push_back(n2);
        }
    }
    Graph& operator=(const Graph& other) {
        if (this == &other)
            return *this;

        clearNodes();
        numEdges = other.numEdges;

        for (Node* n : other.nodes) {
            Node* n2 = new Node(n->id);
            n2->edges = n->edges;
            n2->edgesReversed = n->edgesReversed;
            n2->dijDistance = n->dijDistance;
            n2->dijPath = n->dijPath;
            nodes.push_back(n2);
        }

        return *this;
    }

    size_t vertex_count() const {
        return nodes.size();
    }
    size_t edge_count() const {
        return numEdges;
    }

    bool contains_vertex(size_t id) const {
        return getNode(id) != nullptr;
    }
    bool contains_edge(size_t src, size_t dest) const {
        Node* n = getNode(src);
        if (n == nullptr)
            return false;
        return n->containsEdge(dest);
    }
    double cost(size_t src, size_t dest) const {
        Node* n = getNode(src);
        if (n == nullptr)
            return INFINITY;
        for (Edge e : n->edges)
            if (e.target == dest)
                return e.distance;
        return INFINITY;
    }

    bool add_vertex(size_t id) {
        Node* n = getNode(id);
        if (n != nullptr)
            return false;
        nodes.push_back(new Node(id));
        return true;
    }
    bool add_edge(size_t src, size_t dest, double weight=1) {
        Node* n = getNode(src);
        Node* n2 = getNode(dest);
        if (n == nullptr || n2 == nullptr || n->containsEdge(dest))
            return false;

        n->push(Edge(dest, weight), true);
        n2->push(Edge(src, weight), false);
        numEdges++;
        return true;
    }
    bool remove_vertex(size_t id) {
        Node* n = getNode(id);
        if (n == nullptr)
            return false;
        for (Edge e : n->edgesReversed) {
            Node* n2 = getNode(e.target);
            size_t j = 0;
            for (; j < n2->edges.size(); ++j)
                if (n2->edges.at(j).target == id)
                    break;
            n2->remove(j, true);
            numEdges--;
        }

        for (Edge e : n->edges) {
            Node* n2 = getNode(e.target);
            size_t j = 0;
            for (; j < n2->edgesReversed.size(); ++j)
                if (n2->edgesReversed.at(j).target == id)
                    break;
            n2->remove(j, false);
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
    bool remove_edge(size_t src, size_t dest) {
        Node* n = getNode(src);
        Node* n2 = getNode(dest);
        if (n == nullptr || n2 == nullptr || ! n->containsEdge(dest))
            return false;

        size_t j = 0;
        for (; j < n->edges.size(); ++j)
            if (n->edges.at(j).target == dest)
                break;
        n->edges.erase(n->edges.begin() + j);

        for (j = 0; j < n2->edgesReversed.size(); ++j)
            if (n2->edgesReversed.at(j).target == dest)
                break;
        n2->edgesReversed.erase(n2->edgesReversed.begin() + j);

        numEdges--;
        return true;
    }

    void dijkstra(size_t source_id) {
        for (Node* n : nodes) {
            n->dijDistance = INFINITY;
            n->dijPath.clear();
        }

        Node* start = getNode(source_id);
        if (start == nullptr)
            return;

        Path begin;
        begin.lastNode = start;
        begin.nodeList.emplace_back(begin.lastNode);
        begin.length = 0;

        PriorityQueue<Path, vector<Path>, PathCompare> pq;
        pq.push(begin);

        while (! pq.empty()) {
            Path next = pq.top();
            pq.pop();

            if (next.lastNode->dijDistance <= next.length)
                continue;

            next.lastNode->dijDistance = next.length;
            next.lastNode->dijPath = next.nodeList;

            for (Edge e : next.lastNode->edges) {
                Path p;
                p.lastNode = getNode(e.target);
                p.length = next.length + e.distance;
                p.nodeList = next.nodeList;
                p.nodeList.push_back(p.lastNode);
                pq.push(p);
            }

        }
    }
    double distance(size_t id) const {
        Node* n = getNode(id);
        if (n == nullptr)
            return INFINITY;
        return n->dijDistance;
    }
    void print_shortest_path(size_t dest_id, std::ostream& os = std::cout) const {
        Node* n = getNode(dest_id);
        if (n == nullptr || n->dijDistance == INFINITY) {
            os << "<no path>\n";
            return;
        }
        os << n->dijPath.at(0)->id;
        for (size_t i = 1; i < n->dijPath.size(); ++i)
            os << " --> " << n->dijPath.at(i)->id;
        os << " distance: " << n->dijDistance << "\n";
    }
};

#endif  // GRAPH_H
