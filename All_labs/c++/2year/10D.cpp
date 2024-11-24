#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

void process_queries(int n, int m, int q, vector<vector<int>>& graph, vector<pair<int, int>>& queries) {
    vector<bool> is_red(n + 1, false); // Отслеживаем красные вершины
    vector<int> red_distances(n + 1, 2147483647); // Расстояния до красных вершин
    
    for (auto& query : queries) {
        int type = query.first;
        int v = query.second;
        if (type == 1) {
            // Запрос 1: красим вершину v в красный
            if (!is_red[v]) {
                is_red[v] = true;
                queue<int> bfs_queue;
                bfs_queue.push(v);
                vector<bool> visited(n + 1, false);
                visited[v] = true;

                // Обновляем расстояния до красных вершин
                int distance = 0;
                while (!bfs_queue.empty()) {
                    int size = bfs_queue.size();
                    for (int i = 0; i < size; i++) {
                        int current = bfs_queue.front();
                        bfs_queue.pop();
                        red_distances[current] = min(red_distances[current], distance);
                        for (int neighbor : graph[current]) {
                            if (!visited[neighbor]) {
                                visited[neighbor] = true;
                                bfs_queue.push(neighbor);
                            }
                        }
                    }
                    distance++;
                }
            }
        } else if (type == 2) {
            // Запрос 2: выводим расстояние до ближайшей красной вершины
            if (red_distances[v] == 2147483647) {
                cout << -1 << endl;
            } else {
                cout << red_distances[v] << endl;
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    process_queries(n, m, q, graph, queries);

    return 0;
}
