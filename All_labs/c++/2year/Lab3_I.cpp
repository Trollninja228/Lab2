#include<iostream>
using namespace std;
string bin_search(int arr[], int beg, int end, int key){
	int mid=(beg+end)/2;
	if(arr[mid]==key){
		return "Yes";
	}
	if(beg>=end){
		return "No";
	}
	//recursion
	if(key<arr[mid])
		return bin_search(arr,beg,mid-1,key);
	else
		return bin_search(arr,mid+1,end,key);
	
}
int main(){
	int n;
	int key;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>key;
	cout<<bin_search(arr,0,n,key);
}