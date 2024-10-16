#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
int partition(int *arr, int beg, int end){
    srand(time(NULL));

    int p = beg+rand()%(end-beg);//beg--end

    swap(arr[end], arr[p]);

    int i = beg - 1;
    for(int j=beg;j<end;j++){
        if(arr[j]<=arr[end]){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[end],arr[i+1]);
    return i+1;
}
void quick_sort (int *arr, int beg, int end){
    if(beg<end){
        int p=partition(arr,beg,end);
        quick_sort(arr,beg,p-1);
        quick_sort(arr,p+1,end);
    }
    
}
int bin_search(int* arr, int beg, int end, int key){
	int mid=(beg+end)/2;
	if(arr[mid]==key){
		return mid;
	}
	if(beg>=end){
		// cout<<"not found"<<endl;
		return -1;
	}
	//recursion
	if(key<arr[mid])
		return bin_search(arr,beg,mid-1,key);
	else
		return bin_search(arr,mid+1,end,key);
	
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,n-1);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int i=0;
    int temp=arr[i+1]-arr[i];
    for(i=1;i<n;i++){
        if(temp>abs(arr[i+1]-arr[i])){
            temp=arr[i+1]-arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(temp==arr[i+1]-arr[i]){
            cout<<arr[i]<<" "<<arr[i+1]<<" ";
        }
    }
	
}
