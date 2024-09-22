#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	string s;
	cin>>s;
	int whatever=0; //sbaabsss
	int cycle=1;
	while(cycle){
		//cout<<s<<endl;
		if(s==""){
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
		if(s.size()==1){
			cout<<"No";
			return 0;
		}
		if(s[0]==s[s.size()-1]){
			//cout<<"lol"<<endl;
			s.erase(0,1);
			s.erase(s.size()-1,1);
			whatever=1;
			cycle=1;
		}else{
			for(int j=s.size()-1;j>0;j--){
				//cout<<s[0]<<" "<<s[j]<<endl;
				if(s[0]==s[j]){ //baabss -> aass
					if(j%2==0){
						cout<<"No";
						return 0;
					}
					s.erase(0,1);
					s.erase(j-1,1);
					j+=2;
					whatever=1;
					cycle=1;
					break;
				}else{
					whatever=0;
					cycle=0;
				}
			}
		}
	}
	for(int i=0;i<s.size();i++){
		
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
	



