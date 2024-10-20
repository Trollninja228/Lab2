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
        if(arr[j]>=arr[end]){
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
    int n, m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++){
            cin>>arr[i][j];
        }
    }
    // cout<<endl<<endl;
    int arr1[n];
    for(int j=0;j<m;j++){
        for(int i=0; i<n;i++){
            arr1[i]=arr[i][j];
            // cout<<arr1[i]<<" ";
        }
        // cout<<endl;
        quick_sort(arr1,0,n-1);
        for(int i=0; i<n;i++){
            arr[i][j]=arr1[i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
