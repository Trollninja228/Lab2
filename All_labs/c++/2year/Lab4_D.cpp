#include <iostream>
#include <vector>
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
            //cout<<node->value<<" ";
            inOrderWalk(node->right);
        }
    }
    void print(Node *start){
        inOrderWalk(start);
    }
    Node *search(int x){
        Node *node=root;
        while(node->value!=x){
            if(node->value<x){
                node=node->right;
            }
            if(node->value>x){
                node=node->left;
            }
        }
        return node;
    }
    int calc_level(Node *node){
        int i=0;
        while(node->parent){
            i++;
            node=node->parent;
        }
        return i;
    }
    vector<pair<int,int> > inOrderWalk2(Node* node, vector<pair<int,int> > &v){
        if(node){
            inOrderWalk2(node->left, v);
            pair<int,int> p;
            p.first=calc_level(node);
            p.second=node->value;
            //cout<<p.first<<" "<<p.second<<endl;
            v.push_back(p);
            inOrderWalk2(node->right, v);
        }
        return v;
    }
    vector<pair<int,int> > calc_sum(){
        pair<int,int> p;
        vector<pair<int,int> > v;
        Node *node=root;
        v=inOrderWalk2(node,v);
        return v;
    }
};

int main(){

    BST b;
    int n;
    cin>>n;
    int el;

    for (int i = 0; i < n; i++){
        cin>>el;
        b.insert(el);
    }
    vector<pair<int,int> > v;
    vector<int> v1;
    v=b.calc_sum();
    sort(v.begin(),v.end());
    int sum;
    for (int i = 0; i<v.size(); i++){
        // if(i++!=v.size()){
            sum=v[i].second;
            while(v[i].first==v[i+1].first){
                
                sum+=v[i+1].second;
                i++;
            }
            v1.push_back(sum);
        // }
    }
    cout<<v1.size()<<endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
    
    return 0;
}