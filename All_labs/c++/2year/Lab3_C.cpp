#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v;
    int n,k;
    cin>>n>>k;
    int el;
    for(int i=0; i<n;i++){
        cin>>el;
        v.push_back(el);
    }
    vector<int> v1;
    int l1,r1,l2,r2;
    for(int i=0; i<k;i++){
        cin>>l1>>r1>>l2>>r2;
        v1.push_back(l1);
        v1.push_back(r1);
        v1.push_back(l2);
        v1.push_back(r2);
    }
    int count;
    for(int i=0; i<4*k;i+=4){
        count=0;
        l1=v1[i];
        r1=v1[i+1];
        l2=v1[i+2];
        r2=v1[i+3];
        for(int j=0; j<n;j++){
            if((v[j]>=l1 && v[j]<=r1)||(v[j]>=l2 &&v[j]<=r2)){
                count+=1;
            }
        }
        cout<<count<<endl;
    }
}
