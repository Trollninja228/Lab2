#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void merge(int *arr,int beg,int mid,int end){
    int *left=new int[mid-beg+2];
    int *right=new int[end-mid+1];
    //sentinel
    left[mid-beg+1]=INT_MAX;
    right[end-mid]=INT_MAX;

    //copy from real array
    for (int i = 0; i < mid-beg+1; i++){
        left[i]=arr[beg+i];
    }
    for (int i = 0; i < mid-beg+1; i++){
        right[i]=arr[mid+1+i];
    }
    
}
void mergeSort(int *arr, int beg, int end){
    if(beg<end){
        int mid=(beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end)
    }
}

int main() {
    int arr[7]={7,3,4,5,1,2,6};
    mergeSort(arr,0,6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}
