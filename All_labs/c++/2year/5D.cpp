#include <iostream> 
#include <cstdlib> 
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
        buildMinHeap(); 
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
 
    long long extractMin() { 
         
        long long root = content[0]; 
        content[0] = content[heap_size - 1]; 
        heap_size--; 
        minHeapify(0); 
 
        return root; 
         
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
        heap_size++; 
        long long i = heap_size - 1; 
        content[i] = key; 
 
        while (i != 0 && content[parent(i)] > content[i]) { 
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
 
    int cycle(long long m, long long &num_of_operation){ 
        long long newdensity = 0; 
        long long least_density = extractMin(); 
        long long second_least_density = extractMin(); 
         
        if(least_density <= m ){ 
            newdensity = least_density + 2 * second_least_density; 
            // cout << newdensity <<endl; 
            insertKey(newdensity); 
            // cout<<"yay"<<' '<<heap_size<<endl; 
  
            // cout << least_density << ' '<<second_least_density << endl; 
            if(heap_size <= 1){ 
                cout << -1; 
                exit(0); 
            } 
            num_of_operation++; 
            // cout << num_of_operation << endl; 
            cycle(m, num_of_operation); 
             
             
        } 
        else if(least_density > m){ 
            return num_of_operation; 
        } 
         
         
        return num_of_operation; 
    } 
}; 
 
int main() { 
    long long n, m; 
    cin >> n >> m; 
 
    long long* arr
= new long long[n]; 
    for (long long i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 
 
    Heap myheap(arr, n); 
     
    long long i = 0; 
    long long num_of_operation = myheap.cycle(m, i); 
    cout << num_of_operation; 
 
 
    // myheap.print(); 
     
    delete[] arr; 
    return 0; 
}