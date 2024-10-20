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
    string s;
    cin>>s;
    char el;
    int n=s.size();
    int i_str[n];
    for(int i=0;i<n;i++){
        i_str[i]=s[i];
    }
    quick_sort(i_str,0,n-1);
    for(int i=0;i<n;i++){
        cout<<char(i_str[i]);
    }
}
