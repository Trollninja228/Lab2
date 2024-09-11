#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int main(){
	vector< pair<string,int> > v;
	vector<int> vn;
	pair<string,int> p;
	map<string,int> m;
	string s;
	int n,q;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		p.first=s;
		p.second=i;
		v.push_back(p);
	}
	for(int i=0;i<n;i++){
		s=(v[i]).first;
		if(find(m.begin(),m.end(),s)>=m.begin()&&find(m.begin(),m.end(),s)<m.end()){
		}else{
			m[i]=i;	
		}
	}
	map<string,int>::iterator it=m.begin();
	while(it!=m.end()){
		cout<<(*it).first<<" "<<(*it).second<<endl;
		it++;
	}
}

