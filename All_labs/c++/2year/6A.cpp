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
class Node{
public:
	char value;
	Node *Next;
};
// class Map{
//     public:
//         pair<int,char> value;
//     void fillmap(){
//         char arr[26]={'a','e','i','o','u','y','b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
//         for(int i=0; i<26;i++){
//             Map map;
//             map.value.first=i;
//             map.value.second=arr[i];
//         }
//     }
// };

void out(Node *n, int a){
    for(int i=0;i<a;i++){
        cout<<n->value;
        n=n->Next;
    }
	
}
int findPriority(char *al, char el){
    // cout<<el<<" ";
    int n;
    //aeiouybcdfghjklmnpqrstvwxz;
    for(int i=0;i<26;i++){
        if(al[i]==el){
            n=i;
            break;
        }
    }
    return n;
}
void in(Node* n, int a){
    char elem;
    for(int i=0;i<a;i++){
        cin>>elem;
        n->value=elem;
        n->Next=new Node();
        n=n->Next;
    }
    n->Next=nullptr;
}
// from chars to numbers
void CTN(Node *head,int a, char *al, int*arr){
    Node *node=head;
    for(int i=0; i<a;i++){
        arr[i]=findPriority(al,node->value);
        node=node->Next;
        // cout<<findPriority(al,node->value);
    }
}
void NTC(int *arr, int a, char* al){
    for(int i=0;i<a;i++){
        cout<<al[arr[i]];
    }
}
void Sort(Node *head, int a, char *al){
    int arr[a];
    CTN(head,a,al,arr);
    // for(int i=0;i<a;i++){
    //     cout<<arr[i]<<" ";
    // }
    quick_sort(arr,0,a-1);
    NTC(arr,a,al);
}
int main(){
    char al[26]={'a','e','i','o','u','b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
    long long int a;
    cin>>a;
	Node *head=new Node();
    head->Next=nullptr;
    in(head,a);
    Sort(head,a,al);
    return 0;
}
