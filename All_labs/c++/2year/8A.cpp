#include <iostream> 
#include <string> 
#include <cmath> 
#include <vector> 
#include <algorithm> 
using namespace std; 
  
class Node 
{ 
private: 
    string data; 
    Node* next; 
public: 
    Node(string data){ 
        this->data = data; 
        next = NULL; 
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
        head = NULL; 
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
        if(head == NULL){ 
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
            cout<<curr->getData()<<"<=>"; 
            curr = curr->getNext(); 
        } 
        cout<<endl; 
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
        return NULL; 
    } 
}; 
  
class HashTable 
{ 
private: 
    List* content; 
    unsigned long long int m; 
public: 
    HashTable(unsigned long long int size){ 
        content = new List[size]; 
        m = size; 
    } 
    ~HashTable(){ 
        delete[] content; 
    } 
 
    unsigned long long int power(unsigned long long int a, unsigned long long int b){ 
         
        unsigned long long int perem = a; 
        for(int i = 0; i < b; i++){ 
            perem*=a; 
             
        } 
        return perem; 
    } 
  
    unsigned long long int hash(string s){
        unsigned long long int sum=0;
        for(unsigned long long int i=0; i<s.length();i++){
            // cout<<int(s[i])<<" "<< power(11,i)<<endl;
            sum+=((int(s[i])-47)*power(11,i));
        }
        // cout<<sum<<endl;
        // cout<<power(10,9)+7<<endl;
        return sum%1000000007;
    }
  
    void insert(string s){ 
        // cout << 1 << endl; 
        content[hash(s)].insert(s); 
         
    } 
  
    void print(){ 
        for (unsigned long long int i = 0; i < m; i++) 
        { 
            content[i].print(); 
        } 
    } 
  
    Node* search(string s){ 
        unsigned long long int probe = hash(s); 
        return content[probe].search(s); 
    } 
}; 
  
unsigned long long int power(unsigned long long int a, unsigned long long int b) {
        unsigned long long int result = 1;
        while (b > 0) {
            if (b % 2 == 1){
                result = (result * a) %1000000007;
            }
            a = (a * a) %1000000007;
            b /= 2;
        }
        return result;
    }
unsigned long long int hash(string s){
    unsigned long long int sum=0;
    for(unsigned long long int i=0; i<s.length();i++){
        // cout<<int(s[i])<<" "<< power(11,i)<<endl;
        sum+=((int(s[i])-47)*power(11,i));
    }
    // cout<<sum<<endl;
    // cout<<power(10,9)+7<<endl;
    return sum%1000000007;
}
  
  
  
int main(){
    unsigned long long int n;
    cin>>n;
    HashTable h(10);
    string s;
    // getline(cin,s);
    // getline(cin,s);
    
    for(unsigned long long int i=0;i<2*n;i++){
        cin >> s;
        h.insert(s);
    }
    
    // cout<<toHash("3383080447314675044643313");

}