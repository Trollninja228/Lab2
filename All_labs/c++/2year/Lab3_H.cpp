#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v;
    int el;
    for (int i = 0; i < n; i++) {
        cin>>el;
        v.push_back(el);
    }
    vector<int> v1;
    for (int i = 0; i <k; i++){
        cin>>el;
        v1.push_back(el);
    }
    int sum=0;
    for (int i = 0; i <k; i++){
        sum=0;
        for (int j = 0; j <n; j++){
            sum+=v[j];
            //cout<<"sum: "<<sum<<" "<<v1[i]<<endl;
            if(v1[i]<=sum){
                sum-=v[j];
                cout<<j+1<<endl;
                break;
            }
            
        }
    }  
    
    return 0;
}