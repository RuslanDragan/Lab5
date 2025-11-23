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
    // Ініціалізація: кожен елемент є батьком сам собі
    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}

void Graph::AddWeightedEdge(int u, int v, int w) {
    // Зверніть увагу: ми передаємо вершини як 1-8, але в масив пишемо як 0-7
    G.push_back(make_pair(w, edge(u - 1, v - 1)));
}

int Graph::find_set(int i) {
    // Якщо i є батьком самого себе
    if (i == parent[i])
        return i;
    else
        // Рекурсивний пошук кореня множини
        return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}

void Graph::kruskal() {
    int i, uRep, vRep;
    // Сортуємо всі ребра за зростанням ваги
    sort(G.begin(), G.end());

    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);

        // Якщо вершини в різних множинах (немає циклу)
        if (uRep != vRep) {
            T.push_back(G[i]); // додаємо ребро в дерево
            union_set(uRep, vRep); // об'єднуємо множини
        }
    }
}

void Graph::print() {
    int total_weight = 0;
    cout << "Edge :" << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
        // Виводимо +1, щоб номери співпадали зі схемою (1-8)
        cout << T[i].second.first + 1 << " - " << T[i].second.second + 1 << " : "
             << T[i].first;
        cout << endl;
        total_weight += T[i].first;
    }
    cout << "Total Cost: " << total_weight << endl;
}

int main() {
    // Створюємо граф на 8 вершин
    Graph g(8);

    // Додаємо всі ребра
    // (u, v, weight)
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

    // Запускаємо алгоритм
    g.kruskal();

    // Виводимо результат
    g.print();

    return 0;
}