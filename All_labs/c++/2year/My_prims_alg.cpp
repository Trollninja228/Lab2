#include <bits/stdc++.h>
using namespace std;

struct Graph{
private:
    vector<vector<pair<int,int> > > adj;

    vector <pair<pair<int,bool>,pair<int,int>>> node;
public:
    Graph(int size){
        node.resize(size);
        adj.resize(size);
        for (int i = 0; i < size; i++)
        {
            node[i].first.first=i;
            node[i].first.second=false;
            node[i].second.first=INT_MAX;
            node[i].second.second=-1;
        }
        
    }
    ~Graph(){

    }
    void addEdge(int v1,int v2, int weight){
        pair<int,int> v1_neighbor;
        v1_neighbor.first=v2;
        v1_neighbor.second=weight;


        pair<int,int> v2_neighbor;
        v2_neighbor.first=v1;
        v2_neighbor.second=weight;


        adj[v1].push_back(v1_neighbor);
        adj[v2].push_back(v2_neighbor);
    }
    void print(){
        for (int i = 0; i < adj.size(); i++)
        {
            cout<<i<<":";
            for (pair<int,int> neighbor: adj[i])
            {
                cout<<"("<<neighbor.first<<";"<<neighbor.second<<")";
            }
            cout<<endl;
        }
        
    }
};

int main(){
    Graph g(6);
    g.addEdge(0,1,2);
    g.addEdge(0,5,4);
    g.addEdge(1,2,6);
    g.addEdge(1,4,5);
    g.addEdge(5,2,1);
    g.addEdge(5,4,2);
    g.addEdge(2,3,3);
    g.addEdge(3,4,3);
    g.print();
}