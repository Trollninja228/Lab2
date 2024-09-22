#include <iostream>
#include <string>
using namespace std;
class Node{
public:
	pair<int, int> value;
	Node *Next;
};

void out(Node *n, int a){
    for(int i=0;i<a+1;i++){
        cout<<n->value.second<<" ";
        n=n->Next;
    }
	
}
void in(Node* n, int a){
    int num;
    for(int i=0;i<a;i++){
        cin>>num;
        n->value.first=i+1;
        n->value.second=num;
        n->Next=new Node();
        n=n->Next;
    }
    n->Next=NULL;
}
void insert(Node* n,int a, int data, int pos){
    Node *next;
    if(pos==0){
        next= n->Next;
        n->Next=new Node();
        Node *n_data=n->Next;
        n_data->Next=next;
        n_data->value.second=n->value.second;
        n->value.second=data;
    }else{
        for(int i=0;i<a;i++){
            if(n->value.first==pos){
                next=n->Next;
                n->Next=new Node();
                n=n->Next;
                n->value.first=pos;
                n->value.second=data;
                n->Next=next;
                break;
            }
            n=n->Next;
        }
    }
    
}
int main(){
    long long int a;
    cin>>a;
	Node *head=new Node();
    head->Next=NULL;
    in(head,a);
    int data;
    int pos;
    cin>>data>>pos;
    insert(head,a,data,pos);
    out(head,a);
}
