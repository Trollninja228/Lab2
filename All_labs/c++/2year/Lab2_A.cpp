#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int key;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n==0){
		cout<<0;
		return 0;
	}
	cin>>key;
	int min=abs(arr[0]-key);
	int pos=0;
	for(int i=1;i<n;i++){
		//cout<<abs(arr[i]-key)<<endl;
		if(min>abs(arr[i]-key)){
			//cout<<min<<endl;
			min=abs(arr[i]-key);
			pos=i;
		}
	}
	cout<<pos;
}
