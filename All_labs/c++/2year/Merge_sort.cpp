#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
void merge(int *arr, int beg, int mid, int end){
    int n1=mid-beg+1;
    int n2=end-mid;

    int*left=new int[n1+1];
    int*right=new int[n2+1];
    for(int i=0;i<n1;i++){
        left[i]=arr[beg+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[mid+1+i];
    }
    left[n1]=INT_MAX;
    right[n2]=INT_MAX;

    int i=0;
    int j=0;
    for(int k=beg;k<=end;k++){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
    }
    delete[] left;
    delete[] right;
}
void merge_sort(int *arr, int beg, int end){
    if(beg<end){
        int mid=(beg+end)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }

}
int main() {
    int arr[7]={7,3,4,5,1,2,6};
    merge_sort(arr,0,6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}
