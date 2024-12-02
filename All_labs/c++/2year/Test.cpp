#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

// Функция для подсчёта всех вариантов MST
void countMSTVariants(int n, vector<Edge>& edges, int mstWeight, int& count) {
    sort(edges.begin(), edges.end());
    int totalEdges = edges.size();

    // Перебираем все подмножества рёбер
    for (int mask = 0; mask < (1 << totalEdges); ++mask) {
        UnionFind uf(n);
        int currentWeight = 0;
        int edgeCount = 0;

        for (int i = 0; i < totalEdges; ++i) {
            if (mask & (1 << i)) { // Если ребро включено
                if (uf.unionSets(edges[i].u, edges[i].v)) {
                    currentWeight += edges[i].weight;
                    edgeCount++;
                }
            }
        }

        // Если это MST и имеет минимальный вес
        if (edgeCount == n - 1 && currentWeight == mstWeight) {
            count++;
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

    // Выводим рёбра минимального остовного дерева
    cout << "Рёбра минимального остовного дерева:" << endl;
    for (const auto& edge : mstEdges) {
        cout << "Город " << edge.u << " <-> Город " << edge.v << ", Длина: " << edge.weight << endl;
    }

    // Подсчитаем количество минимальных остовных деревьев
    int mstCount = 0;
    countMSTVariants(n, edges, minWeight, mstCount);
    cout << "Количество минимальных остовных деревьев: " << mstCount << endl;

    return 0;
}
