#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    int size;
    vector<int> color;
    vector<int> discovery;
    vector<int> finish;
    vector<int> predecessor;
    int dfs_time;
    stack<int> topo_sort_stack; // Стек для хранения топологической сортировки

    void dfs_visit(int i) {
        // Store discovery time
        dfs_time++;
        discovery[i] = dfs_time;
        color[i] = 1; // gray

        for (int neighbor : adj[i]) {
            // Go depth-first
            if (color[neighbor] == 0) {
                predecessor[neighbor] = i;
                dfs_visit(neighbor);
            }
        }

        // Store finish time
        dfs_time++;
        finish[i] = dfs_time;
        color[i] = 2;

        // Добавляем вершину в стек после её завершения
        topo_sort_stack.push(i);
    }

public:
    Graph(int size) {
        this->size = size;
        adj.resize(size);
        color.resize(size);
        discovery.resize(size);
        finish.resize(size);
        predecessor.resize(size);
    }

    void addEdge(int v, int u) {
        adj[v].push_back(u);
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<int> bfs(int start) {
        vector<int> color(size, 0); // 0 -- white, 1 -- gray, 2 -- black
        vector<int> discovery(size, INT_MAX);
        vector<int> predecessor(size, -1);

        queue<int> Q;
        color[start] = 1;
        discovery[start] = 0;

        Q.push(start);

        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();

            for (int neighbor : adj[curr]) {
                if (color[neighbor] == 0) {
                    color[neighbor] = 1;
                    discovery[neighbor] = discovery[curr] + 1;
                    predecessor[neighbor] = curr;
                    Q.push(neighbor);
                }
            }
            color[curr] = 2;
        }

        return discovery;
    }

    vector<int> dfs() {
        // Initialization
        for (int i = 0; i < size; i++) {
            color[i] = 0; // whitewash them!
            discovery[i] = INT_MAX;
            finish[i] = INT_MAX;
            predecessor[i] = -1;
        }
        dfs_time = 0;

        for (int i = 0; i < size; i++) {
            if (color[i] == 0) {
                dfs_visit(i);
            }
        }

        return finish;
    }

    void topological_sort() {
        // Выполняем DFS для всех вершин
        dfs();

        // Выводим вершины из стека
        cout << "Topological Sort: ";
        while (!topo_sort_stack.empty()) {
            cout << topo_sort_stack.top() << " ";
            topo_sort_stack.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(8);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 0);
    g.addEdge(6, 4);
    g.addEdge(7, 6);

    g.print();
    g.topological_sort();

    return 0;
}
