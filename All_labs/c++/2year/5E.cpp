#include <iostream> 
#include <vector> 
using namespace std; 
 
class MinHeap { 
private: 
    vector<long long> heap; 
    int heap_size; 
 
    void minHeapify(int i) { 
        int least = i; 
        int l = 2 * i + 1; 
        int r = 2 * i + 2; 
 
        if (l < heap_size && heap[l] < heap[least]) 
            least = l; 
        if (r < heap_size && heap[r] < heap[least]) 
            least = r; 
        if (least != i) { 
            swap(heap[i], heap[least]); 
            minHeapify(least); 
        } 
    } 
 
    void buildMinHeap() { 
        for (int i = heap_size / 2 - 1; i >= 0; i--) { 
            minHeapify(i); 
        } 
    } 
 
    void insertKey(long long key) { 
        if (heap_size < heap.size()) { 
            heap[heap_size++] = key; 
        } else if (key > heap[0]) { 
            heap[0] = key; 
            minHeapify(0); 
        } 
    } 
 
public: 
    MinHeap(int k) { 
        heap.resize(k, 0); 
        heap_size = 0; 
    } 
 
    void addBox(long long cookies) { 
        insertKey(cookies); 
        buildMinHeap(); 
    } 
 
    long long getMaxSum() { 
        long long sum = 0; 
        for (int i = 0; i < heap_size; i++) { 
            sum += heap[i]; 
        } 
        return sum; 
    } 
}; 
 
int main() { 
    int n, k; 
    cin >> n >> k; 
 
    MinHeap minHeap(k); 
 
    string command; 
    for (int i = 0; i < n; i++) { 
        cin >> command; 
        if (command == "insert") { 
            long long cookies; 
            cin >> cookies; 
            minHeap.addBox(cookies); 
        } else if (command == "print") { 
            cout << minHeap.getMaxSum() << endl; 
        } 
    } 
 
    return 0; 
}