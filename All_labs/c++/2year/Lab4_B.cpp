#include <iostream>

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
    int count_of_ch(Node *node, int& count){
        if(node){
            //cout<<2<<endl;
            count++;
            count_of_ch(node->left,count);
            count_of_ch(node->right,count);
        }
        return count;
    }
    int find_size(int x){
        Node *node=root;
        while(node->value!=x){
            //cout<<node->value<<endl;
            if(node->value<x){
                node=node->right;
            }
            if(node->value>x){
                node=node->left;
            }
        }
        int count=0;
        int size=count_of_ch(node,count);
        return size;
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
    int x;
    cin>>x;
    cout<<b.find_size(x);
    return 0;
}