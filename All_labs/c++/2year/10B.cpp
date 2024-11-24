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
    // Undirected Graph
    void addEdge(int v, int u){
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    // void print(){
    //     for (int i = 0; i < size; i++)
    //     {
    //         for (int j = 0; j < adj[i].size(); j++)
    //         {
    //             cout<<adj[i][j]<<"|";
    //         }
    //         cout<<endl;
    //     }
    // }

    vector<int> bfs(int start, int end){
        vector<int> color(size,0);//0 -- white, 1 -- gray, 2 -- black
        vector<int> discovery(size, -1);
        vector<int> predecessor(size, -2);

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
            discovery[i] = 1000000;
            finish[i] = 1000000;
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


int main(){
    int n;
    cin >> n;

    int arr[n][n];
    Graph g(n);
    
    
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                
                g.addEdge(i, j);
            }
            
        }
        
    }


    int start, end;
    cin >> start >> end;
    start -= 1;
    end -= 1;

    vector<int> res = g.bfs(start, end);

    cout << res[end];
   



    return 0;
}