#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
	long long int a,b;
	cin>>a>>b;
	long long int mas[a];
	for(long long int i=0;i<a;i++){
		cin>>mas[i];
	}
	for(long long int i=0;i<a;i++){
		for(long long int j=i;j<a;j++){
			if(mas[i]-mas[j]>b){
				cout<<"cheater";
				return 0;
			}
		}
	}
	cout<<"no";
}
