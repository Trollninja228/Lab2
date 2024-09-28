#include <iostream>

using namespace std;

class Node
{
public:

    Node* parent;
    Node* left;
    Node* right;
    int value;
    pair<int,int> pos;

    Node(pair<pair<int,int>,int> data){
        parent = NULL;
        left = NULL;
        right = NULL;
        value = data.second;
        pos=data.first;
    }
};


class BST
{
private:
    Node* root;
public:
    BST(){
        root = NULL;
    }
    ~BST(){
        clear(root);
    }
    void clear(Node* node){
        if(node){
            clear(node->left);
            clear(node->right);
            delete node;
            //cout<<"You lozer!"<<" ";
        }
    }

    void insert(int i,int j, int newvalue){
        Node* newNode = new Node(make_pair(make_pair(i,j),newvalue));
        Node* x = root;
        Node* y = NULL;
        while(x){
            y = x;
            if(newvalue<x->value)
                x = x->left;
            else
                x = x->right;
        }

        if(y == NULL){
            root = newNode;
        }
        else if(newvalue<y->value){
            newNode->parent = y;
            y->left = newNode;
        }
        else{
            newNode->parent = y;
            y->right = newNode;
        }
    }

    void inOrderWalk(Node* node){
        if(node){
            inOrderWalk(node->left);
            cout<<node->pos.first<<" "<<node->pos.second<<" ";
            inOrderWalk(node->right);
        }
    }

    void print(){
        inOrderWalk(root);
    }
};
int bin_search(Node *root, int beg, int end, int key){
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


main(){

    BST b;
    int num_test;
    cin>>num_test;
    int elements[num_test];
    for (int i = 0; i < num_test; i++)
        {
            cin>>elements[i];
        }
    int a,n;
    cin>>a>>n;
    int el;
    int pos;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>el;
            b.insert(i,j,el);
        }
    }

    b.print();
    return 0;
}