#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	long long int a;
	long long int num;
	cin>>a;
	if(a==1){
		cout<<2;
		return 0;
	}
	for(long long int i=1;i<a;i){
		for(long long int j=3;j;j++){
			int ch=1;
			for(long long int q=2; q<j;q++){
				
				if(j%q==0){
					//cout<<j<<" "<<q<<endl;
					ch=0;
					break;
				}
			}
			if(i>=a){
				cout<<num;
				return 0;
			}
			if(ch){
				i+=1;
				num=j;
			}
		}
	}
	cout<<num;
}
	



