#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adj; //<neighbor, weight>
    int size;

public:
    Graph(int n) : size(n) {
        adj.resize(n);
    }

    void addEdge(int v1, int v2, int weight) {
        adj[v1].emplace_back(v2, weight);
        adj[v2].emplace_back(v1, weight);
    }

    int dijkstra(int root, int dest) {
        vector<int> dist(size, INT_MAX);
        dist[root] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, root);

        while (!pq.empty()) {
            auto [current_dist, u] = pq.top();
            pq.pop();

            if (current_dist > dist[u]) continue;
            if (u == dest) return current_dist;

            for (auto &[v, weight] : adj[u]) {
                int new_dist = current_dist + weight;
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    pq.emplace(new_dist, v);
                }
            }
        }
        return -1; // If destination is unreachable
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.addEdge(a - 1, b - 1, c);
    }

    vector<int> v(4);
    for (int &x : v) cin >> x, x--;

    int n1 = g.dijkstra(v[0], v[1]) + g.dijkstra(v[1], v[2]) + g.dijkstra(v[2], v[3]);
    int n2 = g.dijkstra(v[0], v[2]) + g.dijkstra(v[2], v[1]) + g.dijkstra(v[1], v[3]);

    int n3=min(n1, n2);
    if(n3<0){
        cout<<-1;
    }else{
        cout << n3 << endl;
    }
    return 0;
}
