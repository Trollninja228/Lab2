#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>

using namespace std;

// Структура для ребра
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Класс для структуры данных "Объединение-Пересечение" (Union-Find)
class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) 
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY]) 
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

// Функция для построения MST
int kruskalMST(int n, vector<Edge>& edges, vector<Edge>& mstEdges) {
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    int totalWeight = 0;
    for (const auto& edge : edges) {
        if (uf.unionSets(edge.u, edge.v)) {
            mstEdges.push_back(edge);
            totalWeight += edge.weight;
        }
    }
    return totalWeight;
}

// Рекурсивная функция для поиска всех MST
void findAllMSTs(int n, vector<Edge>& edges, vector<Edge>& currentTree, int currentWeight, int mstWeight, set<vector<Edge>>& allMSTs, int index) {
    if (currentTree.size() == n - 1) {
        if (currentWeight == mstWeight) {
            vector<Edge> sortedTree = currentTree;
            sort(sortedTree.begin(), sortedTree.end(), [](const Edge& a, const Edge& b) {
                if (a.u == b.u) return a.v < b.v;
                return a.u < b.u;
            });
            allMSTs.insert(sortedTree);
        }
        return;
    }

    for (int i = index; i < edges.size(); ++i) {
        UnionFind uf(n);
        for (const auto& edge : currentTree) {
            uf.unionSets(edge.u, edge.v);
        }
        if (uf.unionSets(edges[i].u, edges[i].v)) {
            currentTree.push_back(edges[i]);
            findAllMSTs(n, edges, currentTree, currentWeight + edges[i].weight, mstWeight, allMSTs, i + 1);
            currentTree.pop_back();
        }
    }
}

int main() {
    // Граф: города и рёбра
    vector<Edge> edges = {
        Edge(0, 1, 2),
        Edge(1, 2, 5),
        Edge(2, 3, 4),
        Edge(3, 4, 3),
        Edge(4, 2, 6),
        Edge(4, 5, 7),
        Edge(5, 2, 6),
        Edge(5, 1, 13),
        Edge(5, 0, 7)
    };

    int n = 6; // Количество городов (вершин)
    vector<Edge> mstEdges;

    // Найдём MST с помощью алгоритма Крускала
    int minWeight = kruskalMST(n, edges, mstEdges);
    cout << "Минимальная длина дорог (вес MST): " << minWeight << endl;

    // Найдём все минимальные остовные деревья
    set<vector<Edge>> allMSTs;
    void findAllMSTs(int n, vector<Edge>& edges, vector<Edge> currentTree, int currentWeight, int mstWeight, set<vector<Edge>>& allMSTs, int index);

    // Вывод всех MST
    cout << "Количество минимальных остовных деревьев: " << allMSTs.size() << endl;
    int count = 0;
    for (const auto& mst : allMSTs) {
        cout << "MST #" << ++count << ":" << endl;
        for (const auto& edge : mst) {
            cout << "Город " << edge.u << " <-> Город " << edge.v << ", Длина: " << edge.weight << endl;
        }
        cout << endl;
    }

    return 0;
}
