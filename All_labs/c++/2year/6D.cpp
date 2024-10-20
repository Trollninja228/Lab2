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
    int year,month,day;
    string s;
    int n;
    cin>>n;
    int i=0;
    vector<int> v;
    int m;
    // while(i<n){
    //     i++;
    //     cin>>s;
    //     day=int(s[0])+int(s[1])-2*48;
    //     month=int(s[3])+int(s[4])-2*48;
    //     year=int(s[6])+int(s[7])+int(s[8])+int(s[9])-4*48;
    //     v.push_back(day);
    //     v.push_back(month);
    //     v.push_back(year);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<v[i];
    //     cout<<v[i+1];
    //     cout<<v[i+2];
    // }
    cin>>s;
    cout<<s<<endl;
    cout<<s[0]<<s[1]<<endl;
    string s1;
    s1=string()+ s[0]+s[1];
    day=stoi(s1);
    cout<<day;
    month=int(s[3])+int(s[4])-2*48;
    year=int(s[6])+int(s[7])+int(s[8])+int(s[9])-4*48;
    
}
