#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int IsPrime(int a){
	if(a>=2){
		for(long long int q=2; q<a;q++){
			if(a%q==0){
				return 0;
			}
		}
		return 1;
	} else {
		return 0;
	}
	
}
int main(){
	long long int a;
	long long int num=0;
	vector<int> v;
	cin>>a;
	int q=0;
	for(int i=0;i<a;i){
		q=0;
		for(int j=num+1;1;j++){
			if(IsPrime(j)){
				//cout<<j<<endl;
				q+=1;
				if(IsPrime(q)){
				//cout<<q<<" "<<j<<endl;
				num=j;
				i++;
				if(i>=a){
					break;
					}
				}
			}
			
		}
	}
	cout<<num;
	
	
	
	
}
