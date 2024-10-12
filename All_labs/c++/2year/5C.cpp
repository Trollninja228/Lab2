#include <iostream> 
#include <cmath> 
using namespace std; 
 
class Heap { 
private: 
    long long* content; 
    long long heap_size; 
    long long arr_size; 
public: 
    Heap(long long* arr, long long size) { 
        content = new long long[size]; 
        for (long long i = 0; i < size; i++) { 
            content[i] = arr[i]; 
        } 
        heap_size = size; 
        arr_size = size; 
        buildMaxHeap(); 
    } 
 
    ~Heap() { 
        delete[] content; 
    } 
 
    long long left(long long i) { return 2 * i + 1; } 
    long long right(long long i) { return 2 * i + 2; } 
    long long parent(long long i) { return (i - 1) / 2; } 
 
    void minHeapify(long long i) { 
        long long least = i; 
        long long l = left(i); 
        long long r = right(i); 
 
        if (l < heap_size && content[l] < content[least]) 
            least = l; 
        if (r < heap_size && content[r] < content[least]) 
            least = r; 
        if (least != i) { 
            swap(content[i], content[least]); 
            minHeapify(least); 
        } 
    } 
 
    void maxHeapify(long long i){ 
        long long greatest = i; 
        long long l = left(i); 
        long long r = right(i); 
 
        if (l < heap_size && content[l] > content[greatest]) 
            greatest = l; 
        if (r < heap_size && content[r] > content[greatest]) 
            greatest = r; 
        if (greatest != i) { 
            swap(content[i], content[greatest]); 
            maxHeapify(greatest); 
        } 
    } 
 
    void buildMaxHeap(){ 
        for(long long i = (heap_size / 2) - 1; i>= 0; i--){ 
            maxHeapify(i); 
        } 
    } 
 
    void buildMinHeap() { 
        for (long long i = (heap_size / 2) - 1; i >= 0; i--) { 
            minHeapify(i); 
        } 
    } 
 
    long long extractMin(int amount_of_elems) { 
        if (heap_size <= 0) 
            return -1; 
        if (heap_size == 1) { 
            heap_size--; 
            return content[0]; 
        } 
         
        long long root = content[0]; 
        content[0] = content[heap_size - 1]; 
        heap_size--; 
        minHeapify(0); 
 
        return root;// 42 18 63 26 19 15 11 29 26 24 
        //26 18 19 24 26 26 29 42 63 
    } 
    long long extractMax(int amount_of_elems) { 
        if(amount_of_elems > 1){ 
 
            long long root = content[0]; 
            // cout << root << ' '<<endl; 
            content[0]--; 
            maxHeapify(0); 
            return root; 
        } 
        else{ 
            long long root = content[0]; 
            // cout << root << ' '<<endl; 
            content[0]--; 
            return root; 
        } 
 
        // cout << root<<' '; 
         
        return 0; 
    } 
 
    void insertKey(long long key) { 
        if (heap_size == arr_size) { 
            cout << "\nOverflow: Could not insertKey\n"; 
            return; 
        } 
        heap_size++; 
        long long i = heap_size - 1; 
        content[i] = key; 
 
        while (i != 0 && content[parent(i)] < content[i]) { 
            swap(content[i], content[parent(i)]); 
            i = parent(i); 
        } 
    } 
 
    bool isEmpty() { 
        return heap_size == 0; 
    } 
 
    long long heap_siz1e(){ 
        return heap_size; 
    } 
 
    void print(){ 
        for(int i = 0; i < heap_size; i++){ 
            cout << content[i] << ' '; 
        } 
         
    } 
}; 
 
int main() { 
    long long n, k; 
    cin >> n >> k; 
 
    long long* arr = new long long[n]; 
    for (long long i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 
 
    Heap myheap(arr, n); 
    long long maxsum_of_ticket = 0; 
    while (k != 0) { 
 
         
        long long first = myheap.extractMax(n); 
        maxsum_of_ticket+= first; 
        k--; 
         
    } 
     
    // myheap.print(); 
    cout << maxsum_of_ticket; 
    delete[] arr; 
    return 0; 
}