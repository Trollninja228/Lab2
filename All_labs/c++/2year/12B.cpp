#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Heap {
private:
    vector<pair<int, pair<int, int>>> content;
    int heap_size;

public:
    Heap(vector<pair<int, pair<int, int>>> arr, int size) {
        content.resize(size);
        for (int i = 0; i < size; i++) {
            content[i] = arr[i];
        }
        heap_size = size;
    }

    bool isEmpty() {
        return (heap_size == 0);
    }

    void print() {
        for (int i = 0; i < heap_size; i++) {
            cout << content[i].first << ":(" << content[i].second.first << ";" << content[i].second.second << ")" << endl;
        }
        cout << endl;
    }

    // Indexes
    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (i * 2 + 1);
    }

    int right(int i) {
        return (i * 2 + 2);
    }

    // Heapify
    void minHeapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap_size && content[l].second.first < content[smallest].second.first) // Проверка границ
            smallest = l;
        if (r < heap_size && content[r].second.first < content[smallest].second.first) // Проверка границ
            smallest = r;

        if (smallest != i) {
            swap(content[i], content[smallest]);
            minHeapify(smallest);
        }
    }

    // Build heap
    void buildMinHeap() {
        for (int i = (heap_size - 2) / 2; i >= 0; i--) {
            minHeapify(i);
        }
    }

    // Extract min
    pair<int, pair<int, int>> extractMin() {
        if (isEmpty()) {
            throw runtime_error("Heap underflow");
        }

        pair<int, pair<int, int>> min = content[0];
        swap(content[0], content[heap_size - 1]);
        heap_size--;
        minHeapify(0);
        return min;
    }

    // Decrease key
    void decreaseKey(int v, int newKey, int pred) {
        int index = -1;
        for (int i = 0; i < heap_size; i++) {
            if (v == content[i].first) {
                index = i;
                break;
            }
        }

        if (index == -1 || newKey >= content[index].second.first)
            return;

        content[index].second.first = newKey;
        content[index].second.second = pred;

        while (index > 0 && content[parent(index)].second.first > content[index].second.first) {
            swap(content[parent(index)], content[index]);
            index = parent(index);
        }
    }
};

class Graph {
private:
    vector<vector<pair<int, int>>> adj; //<neighbor, weight>
    vector<pair<int, pair<int, int>>> vert; //<index, <key, pred>>
    vector<bool> visited;

public:
    Graph(int size_v) {
        vert.resize(size_v);
        adj.resize(size_v);
        visited.resize(size_v, false);

        for (int i = 0; i < size_v; i++) {
            vert[i] = {i, {INT_MAX, -1}};
        }
    }

    void addEdge(int v1, int v2, int weight) {
        adj[v1].push_back({v2, weight});
        adj[v2].push_back({v1, weight});
    }

    void print() {
        for (int i = 0; i < adj.size(); i++) {
            cout << i << ":\t";
            for (auto &neighbor : adj[i]) {
                cout << "(" << neighbor.first << ";" << neighbor.second << ")\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    int prim(int root) {
        fill(visited.begin(), visited.end(), false);
        int minCost = 0;
        Heap minHeap(vert, vert.size());

        minHeap.decreaseKey(root, 0, root);
        minHeap.buildMinHeap();

        while (!minHeap.isEmpty()) {
            auto extracted = minHeap.extractMin();
            minCost += extracted.second.first;
            visited[extracted.first] = true;

            for (auto &neighbor : adj[extracted.first]) {
                if (!visited[neighbor.first])
                    minHeap.decreaseKey(neighbor.first, neighbor.second, extracted.first);
            }
        }
        return minCost;
    }

    int dijkstra(int root, int dest) {
        fill(visited.begin(), visited.end(), false);
        Heap minHeap(vert, vert.size());

        minHeap.decreaseKey(root, 0, root);
        minHeap.buildMinHeap();

        while (!minHeap.isEmpty()) {
            auto extracted = minHeap.extractMin();
            visited[extracted.first] = true;
            int initial_cost = extracted.second.first;

            if (extracted.first == dest)
                return initial_cost;

            for (auto &neighbor : adj[extracted.first]) {
                if (!visited[neighbor.first])
                    minHeap.decreaseKey(neighbor.first, neighbor.second + initial_cost, extracted.first);
            }
        }
        return -1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);

    int a, b, c;
    for (int i = 0; i < m; i++) {
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
