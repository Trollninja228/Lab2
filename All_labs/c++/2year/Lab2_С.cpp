#include <iostream>
#include <string>
using namespace std;
class Node{
public:
	int value;
	Node *Next;
};

void out(Node *n, int a){
    for(int i=1;i<=a;i++){
        if(i%2!=0){
            cout<<n->value<<" ";
        }
        n=n->Next;
    }
	
}
void in(Node* n, int a){
    int num;
    for(int i=1;i<=a;i++){
        cin>>num;
        n->value=num;
        n->Next=new Node();
        n=n->Next;
    }
    n->Next=NULL;
}
int main(){
    long long int a;
    cin>>a;
	Node *head=new Node();
    head->Next=NULL;
    in(head,a);
    out(head,a);
}
