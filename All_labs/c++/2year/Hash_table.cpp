#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Node
{
private:
    string data;
    Node* next;
public:
    Node(string data){
        this->data = data;
        next = nullptr;
    }
    string getData(){
        return data;
    }
    Node* getNext(){
        return next;
    }

    void setData(string data){
        this->data = data;
    }

    void setNext(Node* next){
        this->next = next;
    }
};

class List
{
private:
    Node* head;
public:
    List(){
        head = nullptr;
    }
    void clear(Node* node){
        if(node){
            if(node->getNext())
                clear(node->getNext());
            delete node;
        }
    }
    ~List(){
        clear(head);
    }
    void insert(string s){
        Node* newNode = new Node(s);
        if(head == nullptr){
            head = newNode;
        } else{
            Node* curr = head;
            while (curr->getNext())
            {
                curr = curr->getNext();
            }
            curr->setNext(newNode);
        }
    }
    void print(){
        Node* curr = head;
        while(curr){
            cout << curr->getData()<<" ";
            curr = curr->getNext();
            if (curr) cout << "<=> ";
        }
        // cout << endl;
    }
    Node* search(string s){
        if(head){
            Node* curr = head;
            while(curr){
                if(curr->getData() == s)
                    return curr;
                curr = curr->getNext();
            }
        }
        return nullptr;
    }
};

class HashTable
{
private:
    List* content;
    int m;
public:
    HashTable(int size){
        content = new List[size];
        m = size;
    }
    ~HashTable(){
        delete[] content;
    }
    // int hash(string s){
    //     int sum = 0;
    //     for (int i = 0; i < s.length(); i++)
    //     {
    //         sum+= s.at(i)*pow(128,i);
    //     }
    //     return sum%m;
    // }
    int hash(string s){
        int sum = 0;
        int base = 1;
        for (int i = 0; i < s.length(); i++) {
            sum = (sum + int(s[i]) * base) % m;
            base = (base * 128) % m;
        }
        return sum % m;
    }

    void insert(string s){
        content[hash(s)].insert(s);
    }

    void print(){
        for (int i = 0; i < m; i++) {
            content[i].print();
        }
    }

    Node* search(string s){
        int probe = hash(s);
        return content[probe].search(s);
    }
};

int main(){
    HashTable h(10);
    string slow;
    for (int i = 0; i < 3; i++)
    {
        cin>>slow;
        
        h.insert(slow);
    }
    h.print();

    Node* result = h.search("he");
    if (result) {
        cout << "Found: " << result->getData() << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
