#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//undirected
class Graph{
private:
    vector<pair<int, pair<int,int>>> edges;
    int vertix_size;
    vector<int> parent;
    int edge_size;
public:
    Graph(int vertix_size){
        parent.resize(vertix_size);
        this->vertix_size = vertix_size;
        edge_size = 0;
        for (int i = 0; i < vertix_size; i++)
        {
            parent[i] = i;
        }
    }

    void addEdge(int w, int v1, int v2){
        pair<int,pair<int,int>> p;
        p.first = w;
        p.second.first = v1;
        p.second.second = v2;
        edges.push_back(p);
        edge_size++;
    }

    void print(){
        for (int i = 0; i < edge_size; i++)
        {
            int w = edges[i].first;
            int v1 = edges[i].second.first;
            int v2 = edges[i].second.second;
            cout<<v1<<"<->"<<v2<<":"<<w<<endl;
        }   
    }
    
    void merge(int beg, int mid, int end){
        vector<pair<int, pair<int,int>>> left;
        left.resize(mid-beg+2);
        vector<pair<int, pair<int,int>>> right;
        right.resize(end-mid+1);

        //sentinel:
        
        left[mid-beg+1].first = INT_MAX;
        right[end-mid].first = INT_MAX;

        //copy:
        for (int i = 0; i < mid-beg+1; i++)
        {
            left[i] = edges[beg+i];
        }

        for (int i = 0; i < end-mid; i++)
        {
            right[i] = edges[mid+1+i];
        }

        //merging loop:

        int i=0; 
        int j=0; 
        int k=beg;

        while(k<=end){
            if(left[i].first<=right[j].first){
                edges[k] = left[i];
                i++;
                k++;
            }
            else{
                edges[k] = right[j];
                j++;
                k++;
            }
        }    
        
    }
    void mergeSort(int beg, int end){
        if(beg<end){
            int mid = (beg+end)/2;   
            //here 
            mergeSort(beg,mid);
            mergeSort(mid+1,end);
            //there
            merge(beg,mid,end);
        }
    }

    int oldest_predecessor(int v){
        int p = parent[v];
        while (parent[p]!=p)
        {
            p = parent[p];
        }
        return p;
    }

    void change_parents(int v1,int v2){
        int old = oldest_predecessor(v2);
        parent[old] = v1;
    }
    


    int kruskal(){
        mergeSort(0,edge_size-1);

        int minCost = 0;

        for (int i = 0; i < edge_size; i++)
        {
            int w = edges[i].first;
            int v1 = edges[i].second.first;
            int v2 = edges[i].second.second;

            if(oldest_predecessor(v1)!=oldest_predecessor(v2)){
                change_parents(v1,v2);
                minCost+=w;
            }
        }
        

        return minCost;
    }
};




int main()
{   

    Graph g(6);
    g.addEdge(4,0,1);
    g.addEdge(3,0,5);
    g.addEdge(5,2,1);
    g.addEdge(1,1,5);
    g.addEdge(6,2,5);
    g.addEdge(3,2,3);
    g.addEdge(4,3,4);
    g.addEdge(7,4,5);

    cout<<g.kruskal();
    return 0;
}