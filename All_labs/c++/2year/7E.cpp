#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <list> 
 
 
using namespace std;  
 
class CompareWithM {
    int m;
public:
    CompareWithM(int m) : m(m) {}
    bool operator()(int *a, int *b) {
        int sum1=0;
        int sum2=0;
        for(int i=0;i<m;i++){
            sum1+=a[i];
            sum2+=b[i];
        }
        if(sum1!=sum2){
            return sum1>sum2;
        }else{
            for(int i=0;i<m;i++){
                if(a[i]!=b[i]){
                    return a[i]<b[i];
                }
            }
            return false;
        }
        
    }
};
 
 
int main(){ 
  
    int n; 
    int m; 
    cin>> n >> m; 
    vector<int*> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    cout<<endl;
    sort(v.begin(),v.end(),CompareWithM(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0; 
}