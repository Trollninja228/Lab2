#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const long long MOD = 1e9 + 7;

class Node {
public:
    string data;
    Node* next;
    Node(string data) : data(data), next(nullptr) {}
};

class List {
private:
    Node* head;
public:
    List() : head(nullptr) {}
    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insert(string s) {
        Node* newNode = new Node(s);
        newNode->next = head;
        head = newNode;
    }
    bool search(string s) {
        Node* curr = head;
        while (curr) {
            if (curr->data == s) return true;
            curr = curr->next;
        }
        return false;
    }
    string getFirst() {
        return head ? head->data : "";
    }
};

class HashTable {
private:
    List* table;
    unsigned long long size;
public:
    HashTable(unsigned long long size) : size(size) {
        table = new List[size];
    }
    ~HashTable() {
        delete[] table;
    }
    unsigned long long power(unsigned long long a, unsigned long long b) {
        unsigned long long result = 1;
        a = a % MOD;
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }
        return result;
    }
    unsigned long long hash(string s) {
        unsigned long long sum = 0;
        for (unsigned long long i = 0; i < s.length(); i++) {
            sum = (sum + (s[i] - 47) * power(11, i)) % MOD;
        }
        return sum % size;
    }
    void insert(string s) {
        table[hash(s)].insert(s);
    }
    bool search(string s) {
        return table[hash(s)].search(s);
    }
};

int main() {
    unsigned long long n;
    cin >> n;
    cin.ignore();

    string arr[2 * n];
    HashTable hashTable(1000000);

    for (unsigned long long i = 0; i < 2 * n; i++) {
        getline(cin, arr[i]);
    }

    for (unsigned long long i = 0; i < 2 * n; i++) {
        hashTable.insert(arr[i]);
    }

    for (unsigned long long i = 0; i < 2 * n; i++) {
        long long t = hashTable.hash(arr[i]);
        string hash_str = to_string(t);
        if (hashTable.search(hash_str)) {
            cout<<"ANS "<<arr[i]<<endl;
            cout << "Hash of string \"" << arr[i] << "\" is " << t << endl;
        }
        
    }

    return 0;
}
