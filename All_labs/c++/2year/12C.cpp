#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdtr1c++.h>
using namespace std;

class Heap
{
private:
    vector<pair<int,pair<int,int>>> content;
    int heap_size;
public:
    Heap(vector<pair<int,pair<int,int>>> arr, int size){
        content.resize(size);
        for (int i = 0; i < size; i++)
        {
            content[i] = arr[i];
        }
        heap_size = size;
    }
    
    bool isEmpty(){
        return (heap_size == 0);
    }

    void print(){
        for (int i = 0; i < content.size(); i++)
        {
            cout<<content[i].first<<":("<<content[i].second.first<<";"<<content[i].second.second<<")"<<endl;
        }
        cout<<endl;
    }

    //indeces:

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return (i*2+1);
    }

    int right(int i){
        return (i*2+2);
    }

    //heapify:

    void minHeapify(int i){
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if(content[l].second.first<content[smallest].second.first && l<heap_size)//problem
            smallest = l;
        if(content[r].second.first<content[smallest].second.first&& r<heap_size)//problem
            smallest = r;
        
        if(smallest!=i){
            swap(content[i], content[smallest]);
            minHeapify(smallest);
        }
    }


    //maintaining heap property:


    void buildMinHeap(){
        for (int i = (heap_size-2)/2; i >= 0; i--)
        {
            minHeapify(i);
        }
    }


    //heapsort:

    void heapSort(){
        buildMinHeap();// at this point smallest number is at root
        swap(content[0], content[heap_size-1]);
        heap_size--;
        
        while(heap_size>0){
            minHeapify(0);
            swap(content[0], content[heap_size-1]);
            heap_size--;
        }
    }

    pair<int,pair<int,int>> extractMin(){
        pair<int,pair<int,int>> min = content[0];

        swap(content[0],content[heap_size-1]);

        heap_size--;

        minHeapify(0);

        return min;
    }

    void decreaseKey(int v, int newKey, int pred){
        //find vertix v:

        int index;
        for (int i = 0; i < heap_size; i++)
        {
            if(v==content[i].first){
                index = i;
                break;
            }
        }
        
        if(newKey<content[index].second.first){
            content[index].second.first = newKey;
            content[index].second.second = pred;
        }


        //decrease the actual key
        while ((index>0) && (content[parent(index)].second.first>content[index].second.first))
        {
            swap(content[parent(index)],content[index]);
            index = parent(index);
        }
    }
};


class Graph
{
private:
    vector<vector<pair<int, int>>> adj;//<neighbor, weight>

    vector<pair<int, pair<int,int>>> vert;//<index,<key,pred>>

    vector<bool> visited;

public:
    Graph(int size_v){
        vert.resize(size_v);
        adj.resize(size_v);
        visited.resize(size_v);

        for (size_t i = 0; i < size_v; i++)
        {
            vert[i].first = i;
            vert[i].second.first = 2147483647;
            vert[i].second.second = -1;

            visited[i] = false;
        }
    }

    void addEdge(int v1, int v2, int weight){
        pair<int,int> v1_neighbor;
        v1_neighbor.first = v2;
        v1_neighbor.second = weight;
        adj[v1].push_back(v1_neighbor);

        pair<int,int> v2_neighbor;
        v2_neighbor.first = v1;
        v2_neighbor.second = weight;
        adj[v2].push_back(v2_neighbor);
    }

    void print(){
        for (int i = 0; i < adj.size(); i++)
        {
            cout<<i<<":\t";
            for(pair<int,int> neighbor: adj[i]) {
                cout<<"("<<neighbor.first<<";"<<neighbor.second<<")\t";
            }  
            cout<<endl;
        }
        cout<<endl;
    }

    int prim(int root){

        int minCost = 0;
        Heap minHeap(vert,vert.size());

        minHeap.decreaseKey(root,0,root);
        minHeap.buildMinHeap();
        pair<int, pair<int,int>> extracted;
        

        while(!minHeap.isEmpty()){
            extracted = minHeap.extractMin();
            minCost+=extracted.second.first;
            visited[extracted.first] = true;
            for (pair<int,int> neighbor:adj[extracted.first])
            {
                if(!visited[neighbor.first])
                    minHeap.decreaseKey(neighbor.first,neighbor.second,extracted.first);
            }

            minHeap.print();
        }
        return minCost;
    }

    


    int dijikstra(int root, int dest){

        Heap minHeap(vert,vert.size());

        minHeap.decreaseKey(root,0,root);
        minHeap.buildMinHeap();
        pair<int, pair<int,int>> extracted;
        

        while(!minHeap.isEmpty()){
            extracted = minHeap.extractMin();
            visited[extracted.first] = true;
            int initial_cost = extracted.second.first;
            for (pair<int,int> neighbor:adj[extracted.first])
            {
                if(!visited[neighbor.first])
                    minHeap.decreaseKey(neighbor.first,neighbor.second+initial_cost,extracted.first);
            }

            if(extracted.first==dest){
                return extracted.second.first;
            }
            
        }
        
        return -1;
    }

         Graph buildReverseGraph() {
            Graph reverseGraph(adj.size());

            for (int u = 0; u < adj.size(); ++u) {
                for (int v = 0; v < adj.size(); ++v) {
                    if (u != v) {
                        // Проверяем, есть ли ребро между u и v
                        bool hasEdge = false;
                        for (const auto& neighbor : adj[u]) {
                            if (neighbor.first == v) {
                                hasEdge = true;
                                break;
                            }
                        }
                        // Если ребра нет, добавляем его в обратный граф
                        if (!hasEdge) {
                            reverseGraph.addEdge(u, v, 1); // Вес можно оставить 1
                        }
                    }
                }
            }

            return reverseGraph;
        }




};

int main(){

    int n,m;
    cin>>n>>m;
    Graph g(n);

    int a,b;

    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        g.addEdge(--a,--b,1);
    }

    // if (n==5 && m==5){
    //     cout<<2;
    //     return 0;
    // }

    Graph r_g= g.buildReverseGraph();

    // r_g.print();
    int q=--n;
    int ans1=r_g.dijikstra(0,q);
    int ans2=g.dijikstra(0,q);
    // cout<<endl<<q<<endl<<endl;
    // cout<<ans1<<" "<<ans2;
    if(ans1==2147483647){
        cout<<-1;
        return 0;
    }
    if(ans2==2147483647){
        cout<<-1;
        return 0;
    }
    cout<<max(ans1,ans2);
    return 0;
}