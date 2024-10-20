#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iomanip>
using namespace std;
struct student{
    string first_name;
    string last_name;
    float GPA;

    void print(){
        cout<<first_name<<" "<<last_name<<" "<<fixed <<setprecision(3)<<GPA<<endl;
    }
};
int partition(vector<student> &arr, int beg, int end){
    srand(time(NULL));

    int p = beg+rand()%(end-beg);//beg--end

    swap(arr[end], arr[p]);

    int i = beg - 1;
    for(int j=beg;j<end;j++){
        if(arr[j].GPA <= arr[end].GPA){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[end],arr[i+1]);
    return i+1;
}
void quick_sort (vector<student> &arr, int beg, int end){
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
float calcGPA(int m){
    float g1;
    float sum=0;
    float sum1=0;
    string g;
    float c;
    for (int i = 0; i < m; i++){
        cin>>g>>c;
    if(g=="A+"){
        g1=4.000;
    }
    else if(g=="A"){
        g1=3.750;
    }
    else if(g=="B+"){
        g1=3.500;
    }
    else if(g=="B"){
        g1=3.000;
    }
    else if(g=="C+"){
        g1=2.500;
    }
    else if(g=="C"){
        g1=2.000;
    }
    else if(g=="D+"){
        g1=1.500;
    }
    else if(g=="D"){
        g1=1.000;
    }
    else{
        g1=0.000;
    }
        sum+=g1*c;
        sum1+=c;
    }
    return sum/sum1;
    
}
int main(){
    int n,m;
    cin>>n;
    string s;
    string s1;
    vector<student> st(n);
    float GPA;
    for (int i = 0; i < n; i++){
        cin>>s>>s1;
        st[i].first_name=s;
        st[i].last_name=s1;
        cin>>m;
        st[i].GPA=calcGPA(m);
    }
    quick_sort(st,0,n-1);
    for (int i = 1; i < n; i++){
        if(int(st[i].first_name))
    }
    
    for (int i = 0; i < n; i++){
        st[i].print();
    }
    
}
