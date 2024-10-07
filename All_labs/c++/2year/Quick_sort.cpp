#include <iostream>
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
int main() {
    int arr[7]={7,3,4,5,1,2,6};
    quick_sort(arr,0,6);
    // int p=partition(arr,0,6);
    
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    // cout<<endl<<arr[p];
}
