#include <iostream>
#include <vector>
<<<<<<< HEAD
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
=======
#include <queue>
#include <bits/stdc++.h>
using namespace std;


class Graph
{
private:
    vector<vector<int>> adj;
    int size;
    vector<int> color;
    vector<int> discovery;
    vector<int> finish;
    vector<int> predecessor;
    int dfs_time;


    void dfs_visit(int i){
        //store discovery time
        dfs_time++;
        discovery[i] = dfs_time;
        color[i] = 1;//gray


        for (int neighbor:adj[i])
        {   
            //go depth forth!
            if(color[neighbor] == 0){
                dfs_visit(neighbor);
                predecessor[neighbor] = i;
            }
        }

        //store finish time
        dfs_time++;
        finish[i] = dfs_time;
        color[i] = 2;
    }

public:
    Graph(int size){
        this->size = size;
        adj.resize(size);
        color.resize(size);
        discovery.resize(size);
        finish.resize(size);
        predecessor.resize(size);
    }

    void addEdge(int v, int u){
        adj[v].push_back(u);
    }

    vector<int> print(){
        vector<int> v(size);
        for (int i = 0; i < size; i++)
        {
            v[i]=adj[i].size();
        }
        return v;
    }

    vector<int> bfs(int start){
        vector<int> color(size,0);//0 -- white, 1 -- gray, 2 -- black
        vector<int> discovery(size, INT_MAX);
        vector<int> predecessor(size, -1);

        queue<int> Q;
        color[start] = 1;
        discovery[start] = 0;

        Q.push(start);

        while (!Q.empty())
        {
            int curr = Q.front();
            Q.pop();


            for (int neighbor:adj[curr])
            {
                if(color[neighbor] == 0){
                    color[neighbor] = 1;
                    discovery[neighbor] = discovery[curr]+1;
                    predecessor[neighbor] = curr;
                    Q.push(neighbor);
                }
            }
            color[curr] = 2;
        }

        return discovery;

    }   

    vector<int> dfs(){
        //initialization
        for (int i = 0; i < size; i++)
        {
            color[i] = 0;//whitewash them!
            discovery[i] = INT_MAX;
            finish[i] = INT_MAX;
            predecessor[i] = -1;
        }
        dfs_time = 0;


        for (int i = 0; i < size; i++)
        {
            if(color[i]==0){
                dfs_visit(i);
            }
        }

        return finish;
    }


};



int main()
{   
    int n,m;
    cin>>n>>m;

    Graph g(n);
    int a,b;

    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        g.addEdge(a,b);
        
    }
    vector<int> v;
    // cout<<g.kruskal();
    v=g.print();
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i];
    }
    
    return 0;
}
>>>>>>> 1a926d8c338808d0cc6579f5ca4e89c3a9c25029
