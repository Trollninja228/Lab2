#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int kol;
	cin>>kol;
	vector<int> v;
	for(int i=0;i<kol;i++){
		int n;
		cin>>n;
		v.push_back(n);
	}
	vector<int> v1(v);
	v1[0]=-1;
	for(int i=1;i<kol;i++){
		for(int j=i-1;j>=0;j--){
			if(v[j]<=v[i]){
				v1[i]=v[j];
				break;
			}
			if(j==0){
				v1[i]=-1;
			}
		}
	}
	for(int i=0;i<kol;i++){
		cout<<v1[i]<<" ";
	}
}
