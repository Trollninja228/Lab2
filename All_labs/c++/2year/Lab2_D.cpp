#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<int> v, v1,v2;
   
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    int count2 = 0;
    for(int i = 0; i < v.size(); i++){
        int count = 0;
        for(int j = v.size()-1; j  >= 0; j--){
            if(v[i] == v[j]){
               
                count++;
               
            }
            // cout << bool(v[i] == v[j])<<" "<<v[i]<<endl;
            count2++;
           
        }
        v1.push_back(count);
    }
    int max = v1[0];
    int pos = 0;
    for(int i = 0; i < v1.size(); i++){
       
        if(max < v1[i]){
            max = v1[i];
            v2.clear();
            v2.push_back(v[i]);
           
        }
        if(max == v1[i]){
            v2.push_back(v[i]);
        }
    }
    sort(v2.begin(), v2.end());
    for(int i = 1; i < v2.size();i++){
        if(v2[i]==v2[i-1]){
        	v2.erase(v2.begin()+i,v2.begin()+i+1);
        	i--;
		}
    }
   
    for(int i = v2.size() - 1; i >=0;i--){
        cout << v2[i] << ' ' ;
    }
   
   
    return 0;
 
}
