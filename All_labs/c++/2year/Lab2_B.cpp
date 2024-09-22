#include <iostream>
#include <string>
using namespace std;
class Node{
public:
	pair<int,string> value;
	Node *Next;
};

void out(Node *n, int a, int k){
    Node* start=n;
    while(1){
        if(n->value.first==k){
        for(int i=0;i<a-k;i++){
            cout<<((*n).value).second<<" ";
            n=n->Next;
            if(n->Next==NULL){
                for(long long int j=0;j<k;j++){
                    cout<<start->value.second<<" ";
                    start=start->Next;
                }
                break;
            }
        }
        break;
        } else {
            n=n->Next;
        }
    }
    
	
}
void in(Node* n, int a){
    string s;
    
    for(int i=0;i<a;i++){
        cin>>s;
        n->value.first=i;
        ((*n).value).second=s;
        n->Next=new Node();
        n=n->Next;
    }
    n->Next=NULL;
    
}
int main(){
    long long int a;
    long long int k;
    cin>>a>>k;
	Node *head=new Node();
    head->Next=NULL;
    in(head,a);
    out(head,a,k);
}
