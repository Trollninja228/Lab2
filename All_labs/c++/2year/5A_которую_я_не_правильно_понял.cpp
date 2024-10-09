#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Node{
public:
	int value;
	Node *Next;
    Node *prev;
};

void out(Node *n, int a){
    for(int i=0;i<a;i++){
        cout<<n->value<<" ";
        n=n->Next;
    }
	
}
int insert(Node* n,int num){
    Node *step=n;
    Node *temp=step;
    int size=0;
    for (int i = 0; i < num; i++){
        size++;
        cin>>step->value;
        step->Next=new Node();
        temp=step;
        step=step->Next;
        step->prev=temp;
    }
    step->Next=nullptr;
    return size;
}
int SumOfTwoEl(Node *n, int &size){
    int sum;
    Node *node=n;
    Node *temp;
    int mid=size/2;
    for(int i=0;i<mid;i++){
        node=node->Next;
    }
    temp=node->prev;
    temp->value=temp->value+node->value;
    sum=temp->value;
    if(node->Next){
        Node *temp2=node->Next;
        temp->Next=temp2;
        temp2->prev=temp;
    }
    size--;
    delete node;
    return sum;
}
int main(){
    long long int a;
    cin>>a;
	Node *head=new Node();
    head->Next=nullptr;
    head->prev=nullptr;
    int size=insert(head,a);
    vector<int> v;
    while(size>1){
        v.push_back(SumOfTwoEl(head,size));
    }
    out(head,size);
    cout<<endl;
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    cout<<sum;
}
