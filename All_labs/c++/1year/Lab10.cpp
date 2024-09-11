#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
using namespace std;
int main(){
	int n,q;
	cin>>n;
	vector< vector<int> > v(5);
	vector<int> v1;
	for(int i=0;i<n;i++){
		while(cin>>q){
			v1.push_back(q);
		}
		v.push_back(v1);
	}
	for(int i=0;i<v.size();i++){
		
	}
}


