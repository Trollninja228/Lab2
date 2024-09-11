#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
/*
4
first 20
second 21.5

*/
void coutMap(map<string,float> m){
	map<string,float>::iterator it=m.begin();
	while (it!=m.end()){
		cout<<it->first<<"-->"<<it->second<<endl;   //or cout<<(*it).first<"-->"<<(*it).second<<endl; тоесть итератор становиться парой
		it++;
	}
}
int main(){
	freopen ("input.txt","r",stdin);
	map<string, map<string,float> > m;
	int n;
	cin>>n;
	string id;
	float point;
	for(int i=0;i<n;i++){
		cin>>id>>point;
		m[id]=point;
	}
	map<string, map<string,float>> p(Me, (math, 22.5));
	m.insert(p);
	coutMap(m);
}
