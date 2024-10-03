#include <iostream>
#include <algorithm>
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
    void inOrderWalk2(Node* node,int x){
        if(node){
            cout<<node->value<<" ";
            inOrderWalk2(node->left,x);
            inOrderWalk2(node->right,x);
        }
    }
    void print(Node *start,int x){
        inOrderWalk2(start,x);
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
    Node *search(int x){
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
        return node;
    }

    void sum_of(int left, int right){
        
        cout << find_levels(root, left, right);
    }
    int find_levels(Node*node, int left, int right){
        
            if(node){
                find_levels(node->right, left, right);
                left++;
                cout<<node->value<<" ";
                find_levels(node->left, left, right);
                right++;
            }
        
        return max(left, right);
    }

    void find_sum_of_levels(){
        Node *newnode = root;
        int left = 0;
        while(newnode){
            newnode = newnode->left;
            left++;
        }
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
    
    b.sum_of(0, 0);
    
    
    
    return 0;
}