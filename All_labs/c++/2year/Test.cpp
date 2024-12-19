#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>

using namespace std;
int dfs_time;
vector<int> color;
vector <int>discovery;
vector<int> predecessor;
vector<int> finish;
int size;
size=5;
vector<vector<int>> adj(size);

void dfs_visit(int i){
    dfs_time++;
    discovery[i]=dfs_time;
    color[i]=1;

    for (int neighbour:adj[i])
    {
        if(color[neighbour]==0){
            dfs_visit(neighbour);
            predecessor[neighbour]=i;
        }
    }
    dfs_time++;
    finish[i]=dfs_time;
    color[i]=2;
}
vector<int> dfs(){

    for (int i = 0; i < size; i++)
    {
        color[i]=0;
        discovery[i]=INT_MAX;
        finish[i]=INT_MAX;
        predecessor[i]=-1;
    }
    dfs_time=0;

    for (int i = 0; i < size; i++)
    {
        if(color[i]==0){
            dfs_visit(dfs_time);
        }
    }
    
    return finish;
    
}