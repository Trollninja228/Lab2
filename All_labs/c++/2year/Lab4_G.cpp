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
    void inOrderWalk2(Node* node,vector <Node> &v){
        if(node){
            inOrderWalk2(node->left,v);
            if(node->left==nullptr && node->right==nullptr){
                v.push_back(*node);
            }
            inOrderWalk2(node->right,v);
        }
    }
    void print(){
        inOrderWalk(root);
    }
    int calc_level(Node *node){
        int i=0;
        while(node->parent){
            i++;
            node=node->parent;
        }
        return i;
    }
    vector <Node> find_ends(){
        vector<Node> v;
        inOrderWalk2(root,v);
        return v;
    }
    vector <Node*> find_common_parent(vector<Node*> &v, vector<int> &v1){
        Node *node;
        Node *node1;
        vector<Node*> v2;
        for(int i=1;i<v.size();i++){
            for (size_t j = 0; j < v.size(); j++){
                if(v[j]!=v[i]){
                    node=v[i];
                    node1=v[j];
                    if(calc_level(node)==calc_level(node1)){
                        if(node->value == node1->value){
                            v2.push_back(node);
                        }else{
                            node=node->parent;
                            node1=node1->parent;
                        }
                    }else{
                        if(calc_level(node)<calc_level(node1)){
                            node1=node1->parent;
                        }else{
                            node=node->parent;
                        }
                    }
                }
            }
            
            
                
        }
        return v2;
    }
};



main(){

    BST b;
    int n;
    cin>>n;
    int el;
    vector <Node> v;
    for (int i = 0; i < n; i++){
        cin>>el;
        b.insert(el);
    }
    v=b.find_ends();
    vector <Node*> v1;
    vector <Node*> v2;
    b.find_common_parent(v,v1);
    // for (int i = 0; i <v.size(); i++){
    //     cout<<v[i].value<<" ";
    // }

    return 0;
}