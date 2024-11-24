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
    stack<int> topo_sort_stack;

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

    void topological_sort(vector<string>name) {
        dfs();

        while (!topo_sort_stack.empty()) {
            cout << name[topo_sort_stack.top()] << " ";
            topo_sort_stack.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(9);
    vector<string> names(9);

    names[0] = "shirt";
    names[1] = "tie";
    names[2] = "jacket";
    names[3] = "belt";
    names[4] = "pants";
    names[5] = "undershorts";
    names[6] = "socks";
    names[7] = "shoes";
    names[8] = "watch";


    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(0,3);
    g.addEdge(4,3);
    g.addEdge(5,4);
    g.addEdge(5,7);
    g.addEdge(6,7);
    g.addEdge(4,7);
    g.addEdge(8, 8);

    g.topological_sort(names);

    return 0;
}
 