#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Node {
private:
    string data;
    Node* next;
public:
    Node(string data) : data(data), next(nullptr) {}
    
    string getData() {
        return data;
    }
    Node* getNext() {
        return next;
    }
    void setNext(Node* next) {
        this->next = next;
    }
};

class List {
private:
    Node* head;
public:
    List() : head(nullptr) {}
    
    void insert(string s) {
        Node* newNode = new Node(s);
        if (!head) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->getNext()) {
                curr = curr->getNext();
            }
            curr->setNext(newNode);
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }
    
    Node* search(string s) {
        Node* curr = head;
        while (curr) {
            if (curr->getData() == s) return curr;
            curr = curr->getNext();
        }
        return nullptr;
    }
    
    string getFirst() {
        return head->getData();
    }
};

class HashTable {
private:
    List* content;
    long long int m;
public:
    HashTable(long long int size) : m(size) {
        content = new List[size];
    }
    ~HashTable() {
        delete[] content;
    }

    long long int hash(string s) {
        long long int sum = 0;
        long long int base = 1;
        for (long long int i = 0; i < s.length(); i++) {
            sum += ((int(s[i]) - 47) * base);
            base = (base * 11) % 1000000007;
        }
        return sum % m;
    }

    void insert(string s) {
        content[hash(s)].insert(s);
    }

    bool comp_hash_string(string s) {
        return !content[stoi(s) % m].isEmpty();
    }
    
    void check(int n, string* id) {
        for (long long int i = 0; i < 2 * n; i++) {
            if (id[i].length() < 19) {
                if (comp_hash_string(id[i])) {
                    long long int idx = stoi(id[i]) % m;
                    string data = content[idx].getFirst();
                    if (!data.empty()) {
                        cout << "Hash of string \"" << data << "\" is " << id[i] << endl;
                    } else {
                        cout << "Hash of string \"\" is " << id[i] << endl;
                    }
                }
            }
        }
    }
};

int main() {
    HashTable h(10000);
    long long int n;
    cin >> n;
    string id[2 * n];
    for (long long int i = 0; i < 2 * n; i++) {
        cin >> id[i];
        h.insert(id[i]);
    }
    h.check(n, id);
    return 0;
}
