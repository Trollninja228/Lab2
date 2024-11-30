#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (parent[v] != v) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    void unionSets(int v1, int v2) {
        int root1 = find(v1);
        int root2 = find(v2);
        
        if (root1 != root2) {
            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;  // (cost, (vertex1, vertex2))

    // Чтение входных данных
    for (int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        l--; r--;  // Переводим индексы в 0-индексацию

        // Генерация рёбер для всех пар (x, y) таких что l ≤ x < y < r
        for (int x = l; x < r; x++) {
            for (int y = x + 1; y < r; y++) {
                edges.push_back({c, {x, y}});
            }
        }
    }

    // Сортировка рёбер по стоимости
    sort(edges.begin(), edges.end());

    UnionFind uf(n);  // Инициализация Union-Find
    long long mstCost = 0;
    int edgeCount = 0;

    // Применение алгоритма Краскала
    for (auto& edge : edges) {
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (uf.find(u) != uf.find(v)) {
            uf.unionSets(u, v);
            mstCost += cost;
            edgeCount++;
        }

        // Если все вершины уже объединены, можно завершить
        if (edgeCount == n - 1) {
            break;
        }
    }

    cout << mstCost << endl;
    return 0;
}
