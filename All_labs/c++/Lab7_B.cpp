#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
	long long int a,q,u;
	cin>>a;
	if(a%2==0){
		q=a/2;
	}else{
		q=(a/2)+1;
	}
	long long int b[q];
	for(long long int i=q-1;i>=0;i--){
		if(a%2==0){
			b[i]=0;
		} else{
			b[i]=1;
		}
		a=a/2;
	}
	for(long long int i=0;i<q;i++){
		if(b[i]==0){
			
		}else{
			u=i;
			break;
		}
	}
	for(int i=u;i<q;i++){
		cout<<b[i];
	}
}
