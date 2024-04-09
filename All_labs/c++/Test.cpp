#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int main(){
	int n,a;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	v.erase(v.begin(),v.begin()+2);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}


