#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:

    Node* parent;
    Node* left;
    Node* right;
    int value;

    Node(int data){
        parent = NULL;
        left = NULL;
        right = NULL;
        value = data;
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

    void insert(int newvalue){
        Node* newNode = new Node(newvalue);
        
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
            cout<<node->value<<" ";
            inOrderWalk(node->right);
        }
    }

    void print(){
        inOrderWalk(root);
    }
    void inOrderWalk2(Node* node, int &n){
        if(node){
            inOrderWalk2(node->right,n);
            n+=node->value;
            cout<<n;
            inOrderWalk2(node->left,n);
            
        }
    }
    void sum(){
        int sum=0;
        Node *node=new Node(0);
        while(node->right!=NULL){
            node=node->right;
        }
        int n=node->value;
        inOrderWalk2(node,n);
    }
};



main(){

    BST b;
    int n;
    cin>>n;
    int el;

    for (int i = 0; i < n; i++){
        cin>>el;
        b.insert(el);
    }
    
    b.sum();
    return 0;
}