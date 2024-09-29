#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n,k,l1,l2,r1,r2;
    cin>>n>>k;
    vector<int> v;
    int maximum=0;
    int most=0;
    for (int i = 0; i < n; i++) {

        cin>>l1>>r1>>l2>>r2;
        most=max(l2,r2);
        if(maximum<most){
            maximum=most;
        }
        v.push_back(most);
    }
    sort(v.begin(),v.end());
    int size=1;
    int num=0;
    for (int i = 0; i <n; i++){
        if(num==k){
            cout<<size;
            return 0;
        }
        if(v[i]<=size){
        }else{
            size=v[i];
        }
        num++;
        if(num==k){
            cout<<size;
            return 0;
        }
    }
       
    
    return 0;
}