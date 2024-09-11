#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s==""){
		cout<<"Yes";
		return 0;
	}
	if(s.size()==1){
		cout<<"Yes";
		return 0;
	}
	if(s.size()==2){
		if(s[0]==s[1]){
			cout<<"Yes";
		}else{
			cout<<"No";
		}
		return 0;
	}
	if(s.size()==3){
		if(s[0]==s[2]){
			cout<<"Yes";
		}else{
			cout<<"No";
		}
		return 0;
	}
	int whatever=0;
	while(s.size()!=0){
		if(s[0]==s[-1]){
			s.erase(0,1);
			s.erase(-1,1);
			cout<<s;
		}else{
			for(int i=1;i<s.size();i++){
				if(s[i]==s[0]){
					s.erase(0,i+1);
					break;
					whatever=1;
					cout<<s;
				}else{
					whatever=0;
				}
			}
		}
		
	}
	if(s==""){
		cout<<"Yes";
		return 0;
	}
	if(whatever==1){
		cout<<"Yes";
		return 0;
	}else{
		cout<<"No";
	}
}
	



