#include <iostream>
#include <vector>
#include <queue>
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

    void print(){
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout<<adj[i][j]<<"|";
            }
            cout<<endl;
        }
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
    Graph g(8);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,3);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(6,0);
    g.addEdge(6,4);
    g.addEdge(7,6);
    g.addEdge(7,5);




    vector<int> v = g.dfs();

    for (int i = 0; i < 8; i++)
    {
        cout<<v[i]<<"|";
    }
    cout<<endl;

    return 0;
}