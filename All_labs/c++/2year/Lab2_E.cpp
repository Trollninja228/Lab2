#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    vector<string> v;
    long long int n;
    cin>>n;
    string s;
    string s1;
    cin>>s;
    v.push_back(s);
    int j=1;
    for(long long int i=1;i<n;i++){
        cin>>s;
        if(v[j-1]!=s){
            v.push_back(s);
            j++;
        }
    }
    cout<<"All in all: "<<v.size()<<endl;
    cout<<"Students:"<<endl;
    for(long long int i=v.size()-1;i>-1;i--){
        cout<<v[i]<<endl;
    }
}
