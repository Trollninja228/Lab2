#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Node {
private:
    string data;
    Node* next;
public:
    Node(string data) {
        this->data = data;
        next = nullptr;
    }
    string getData() {
        return data;
    }
    Node* getNext() {
        return next;
    }

    void setData(string data) {
        this->data = data;
    }

    void setNext(Node* next) {
        this->next = next;
    }
};

class List {
private:
    Node* head;
public:
    List() {
        head = nullptr;
    }
    void clear(Node* node) {
        if (node) {
            if (node->getNext())
                clear(node->getNext());
            delete node;
        }
    }
    ~List() {
        clear(head);
    }
    void insert(string s) {
        Node* newNode = new Node(s);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->getNext()) {
                curr = curr->getNext();
            }
            curr->setNext(newNode);
        }
    }
    void print() {
        Node* curr = head;
        while (curr) {
            cout << curr->getData() << "<=>";
            curr = curr->getNext();
        }
        cout << endl;
    }
    Node* search(string s) {
        if (head) {
            Node* curr = head;
            while (curr) {
                if (curr->getData() == s)
                    return curr;
                curr = curr->getNext();
            }
        }
        return nullptr;
    }
};

class HashTable {
private:
    List* content;
    int m;
public:
    HashTable(int size) {
        content = new List[size];
        m = size;
    }
    ~HashTable() {
        delete[] content;
    }

    long long calculate_hash(const string& s) {
        const long long MOD = 1e9 + 7; // Define MOD as long long
        long long hash_value = 0;
        for (char ch : s) {
            hash_value = (hash_value + (static_cast<int>(ch) - 47)) % MOD;
        }
        hash_value = (hash_value * (11 * 11)) % MOD; // 11^2
        return hash_value;
    }

    void insert(string s) {
        content[calculate_hash(s) % m].insert(s); // Ensure index is within bounds
    }

    void print() {
        for (int i = 0; i < m; i++) {
            content[i].print();
        }
    }

    Node* search(string s) {
        return content[calculate_hash(s) % m].search(s);
    }
};

int main() {
    HashTable h(100); // Increased size for better distribution

    // Sample strings to insert
    string items[] = {"111", "266", "123456789", "93085", "334368200", "100000"};

    // Insert each item into the hash table
    for (const auto& item : items) {
        h.insert(item);
    }

    // Print all items in the hash table
    // h.print();

    // Check for specific hashes
    string checkItems[] = {"111", "123456789", "93085", "266", "334368200", "100000"};
    for (const auto& item : checkItems) {
        Node* result = h.search(item);
        if (result) {
            cout << "Hash of string \"" << item << "\" is " << h.calculate_hash(item) << endl;
        }
    }

    return 0;
}
