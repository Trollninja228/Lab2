#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
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
    int n,m;
    cin>>n>>m;
    int arr1[n];
    int arr2[m];
    for (int i = 0; i < n; i++){
        cin>>arr1[i];
    }
    for (int i = 0; i < m; i++){
        cin>>arr2[i];
    }
    quick_sort(arr1,0,n-1);
    quick_sort(arr2,0,m-1);
    int temp;
    if(n&&m){
        if(n>m){
            int j=0;
            for(int i=0;i<n;i++){
                // cout<<"el "<<arr2[i]<<endl;
                temp=bin_search(arr2,0,m-1,arr1[i]);
                if(temp>-1){
                    arr2[j]=-1;
                    j++;
                    // cout<<"temp "<<temp<<endl;
                    cout<<arr1[i]<<" ";
                }
            }
        }else{
            int j=0;
            for(int i=0;i<m;i++){
                temp=bin_search(arr1,0,n-1,arr2[i]);
                if(temp>-1){
                    arr1[i]=-1;
                    j++;
                    cout<<arr2[i]<<" ";
                }
            }
        }
    }
	
}
