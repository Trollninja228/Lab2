#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	long long int a,b,q,c,sum;
	string s;
	cin>>s;
	vector<char> v;
	//cin
	for(int i=0;i<s.size();i++){
		v.push_back(s[i]);
	}
	//solution
	for(int i=0;i<v.size();i++){
		if((int)v[i]>=65&&(int)v[i]<=90){
			v[i]=(char)((int)v[i]+32);
		}
	}
	for(int j=0;j<v.size();j++){
		for(int i=j+1;i<v.size();i){
			if(v[j]==v[i]){
				v.erase(v.begin()+i);
			}else{
				i++;
			}
		}
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
