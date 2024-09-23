#include<iostream>
using namespace std;
struct Node{
public:
	int value;
	Node *left;
	Node *right;
	Node *previous;

	Node(int data){
		value=data;
		previous=NULL;
		left=NULL;
		right=NULL;
	}
};
void clear(Node *head){
	if(head){
		clear(head->left);
		clear(head->right);
		delete head;
	}
}

void insert(Node *root, int data){
	Node *Data=new Node(data);
	Node *x=root;
	Node *y=NULL;
	while(x){
		y=x;
		if(data<x->value){
			x=x->left;
		}else{
			x=x->right;
		}
	}
	if(y==NULL){
		root=Data;
	}else if(data<y->value){
		Data->previous=y;
		y->left=Data;
	}else{
		Data->previous=y;
	}
	
}
void inOrderWalk(Node *node){
	if(node){
		inOrderWalk(node->left);
		cout<<node->value<<" ";
		inOrderWalk(node->right);
	}
}
void printNode(Node *root){
	inOrderWalk(root);
}


int bin_search(int* arr, int beg, int end, int key){
	int mid=(beg+end)/2;
	if(arr[mid]==key){
		return mid;
	}
	if(beg>=end){
		cout<<"not found"<<endl;
		return INT_MAX;
	}
	//recursion
	if(key<arr[mid])
		return bin_search(arr,beg,mid-1,key);
	else
		return bin_search(arr,mid+1,end,key);
	
}
int main(){
	Node *root;
	int arr[7]={1, 2, 3, 4, 5, 6, 7};
	for(int i=0;i<7;i++){
		insert(root, arr[i]);
	}
	printNode(root);
}
