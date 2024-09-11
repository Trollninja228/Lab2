#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int m[n];
	for (int i=0;i<n;i++){
		cin>>m[i];
	}
	int b=1;
	for (b;b<n;b++){
		for (int i=0;i<b;i++){
			if (m[i]>m[b]){
				int j=b;
				while(j>i){
					int q=m[j];
					m[j]=m[j-1];
					m[j-1]=q;
					j--;
				}
			}
		}
	}
	for (int i=0;i<n;i++){
		cout<<m[i];
	}
}
