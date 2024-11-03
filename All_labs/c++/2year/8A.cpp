#include <iostream>
#include <cstring>
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
    bool isEmpty() const {
        return head == nullptr;
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
    string getFirst(){
        return head->getData();
    }
};
class HashTable
{
private:
    List* content;
    long long int m;
public:
    HashTable(long long int size){
        content = new List[size];
        m = size;
    }
    ~HashTable(){
        delete[] content;
    }
    // long long int hash(string s){
    //     long long int sum = 0;
    //     for (long long int i = 0; i < s.length(); i++)
    //     {
    //         sum+= s.at(i)*pow(128,i);
    //     }
    //     return sum%m;
    // }
    long long int hash(string s){
        long long int sum = 0;
        long long int base = 1;
        for (long long int i = 0; i < s.length(); i++) {
            sum += (( int(s[i])-47) * base);
            base = (base * 11) % 1000000007;
        }
        // cout<<sum;
        return sum % m;
    }

    void insert(string s){
        content[hash(s)].insert(s);
    }

    void print(){
        for (long long int i = 0; i < m; i++) {
            content[i].print();
        }
    }

    Node* search(string s){
        long long int probe = hash(s);
        return content[probe].search(s);
    }
    string data(long long int n){
        return content[n].getFirst();
    }
    bool comp_hash_string(string s){
        return content[stoi(s)%m].isEmpty();
    }
    void check(int n, string *id){
        for (long long int i = 0; i < 2*n; i++) {
            if(id[i].length()<19){
                if(comp_hash_string(id[i])){
                    long long int idx = stoi(id[i]) % m;
                    string res=content[idx].getFirst();
                    // cout<<stoi(id[i])%10000<<" "<<i<<endl;
                    cout<<"Hash of string \"" <<res<<"\" is "<<id[i]<<endl;
                }
            }
        }
    }
};

int main(){
    HashTable h(10000);
    string slow;
    long long int n;
    cin>>n;
    string id[2*n];
    for (long long int i = 0; i < 2*n; i++)
    {
        cin>>id[i];
        h.insert(id[i]);
    }
    h.check(n, id);
    // h.print();
    return 0;
}
