#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


#define edge pair<int, int>

class Graph {
private:

    vector<pair<int, edge>> G;

    vector<pair<int, edge>> T;
    int *parent;
    int V;

public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};

Graph::Graph(int V) {
    this->V = V;
    parent = new int[V];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}

void Graph::AddWeightedEdge(int u, int v, int w) {

    G.push_back(make_pair(w, edge(u - 1, v - 1)));
}

int Graph::find_set(int i) {

    if (i == parent[i])
        return i;
    else

        return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}

void Graph::kruskal() {
    int i, uRep, vRep;

    sort(G.begin(), G.end());

    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);


        if (uRep != vRep) {
            T.push_back(G[i]);
            union_set(uRep, vRep); 
        }
    }
}

void Graph::print() {
    int total_weight = 0;
    cout << "Edge :" << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {

        cout << T[i].second.first + 1 << " - " << T[i].second.second + 1 << " : "
             << T[i].first;
        cout << endl;
        total_weight += T[i].first;
    }
    cout << "Total Cost: " << total_weight << endl;
}

int main() {

    Graph g(8);


    g.AddWeightedEdge(1, 3, 1);
    g.AddWeightedEdge(1, 4, 4);
    g.AddWeightedEdge(1, 2, 4);

    g.AddWeightedEdge(2, 6, 3);
    g.AddWeightedEdge(2, 5, 7);

    g.AddWeightedEdge(3, 4, 5);
    g.AddWeightedEdge(3, 6, 5);
    g.AddWeightedEdge(3, 8, 4);

    g.AddWeightedEdge(4, 5, 1);

    g.AddWeightedEdge(5, 7, 4);

    g.AddWeightedEdge(6, 7, 6);

    g.AddWeightedEdge(7, 8, 5);


    g.kruskal();


    g.print();

    return 0;

}
