#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	string s;
	string s1;
	cin>>s>>s1;
	for(int i=1;i<s.size();i++){
		if(s[i]=='#'){
			s.erase(i-1,2);
			i-=2;
		}
		
	}for(int i=1;i<s1.size();i++){
		if(s1[i]=='#'){
			s1.erase(i-1,2);
			i-=2;
		}
		
	}
	if(s==s1){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}
