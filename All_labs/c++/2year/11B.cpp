#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void del_min(vector<int>& v, int min){
    for (int i = 0; i < v.size(); i++){
        if(min==v[i]){
            v.erase(v.begin()+i,v.begin()+i+1);
            return;
        }
    }
    
}

int main()
{   
    int n;
    cin>>n;
    vector<int> v(n);
    int min=2147483647;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]<min){
            min=v[i];
        }
    }
    del_min(v,min);
    int sum=0;
    for (int i = 0; i < n-1; i++)
    {
        // cout<<v[i]<<' ';
        sum+=min+v[i];
    }
    cout<<sum;
}