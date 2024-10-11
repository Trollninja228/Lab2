#include <iostream> 
#include <cmath> 
using namespace std; 
 
class MaxHeap { 
private: 
    long long* content; 
    long long heap_size; 
    long long arr_size; 
public: 
    MaxHeap(long long* arr, long long size) { 
        content = new long long[size]; 
        for (long long i = 0; i < size; i++) { 
            content[i] = arr[i]; 
        } 
        heap_size = size; 
        arr_size = size; 
        buildMaxHeap(); 
    } 
 
    ~MaxHeap() { 
        delete[] content; 
    } 
 
    long long left(long long i) { return 2 * i + 1; } 
    long long right(long long i) { return 2 * i + 2; } 
    long long parent(long long i) { return (i - 1) / 2; } 
    void maxHeapify(long long int i) {
        long long int largest = i;
        long long int l = left(i);
        long long int r = right(i);

        if (l < heap_size && content[l] > content[largest]) {
            largest = l; // Находим наименьший элемент
        }
        if (r < heap_size && content[r] > content[largest]) {
            largest = r; // Находим наименьший элемент
        }

        if (largest != i) {
            swap(content[i], content[largest]); // Меняем местами
            maxHeapify(largest); // Рекурсивно восстанавливаем кучу
        }
    }
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
    void buildMaxHeap() { 
        for (long long i = (heap_size / 2) - 1; i >= 0; i--) { 
            maxHeapify(i); 
        } 
    } 
    void buildMinHeap() { 
        for (long long i = (heap_size / 2) - 1; i >= 0; i--) { 
            minHeapify(i); 
        } 
    } 
 
    long long extractMin() { 
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
 
        return root;
    } 
    long long extractMax() { 
        if (heap_size <= 0) 
            return -1; 
        if (heap_size == 1) { 
            heap_size--; 
            return content[0]; 
        } 
 
        long long root = content[0]; 
        content[0] = content[heap_size - 1]; 
        heap_size--; 
        maxHeapify(0); 
        return root;
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
    void print() {
        for (long long int i = 0; i < heap_size; i++) {
            cout << content[i] << " ";
        }
        cout << endl;
    }
}; 
 
int main() { 
    long long n; 
    cin >> n; 
 
    long long* arr = new long long[n]; 
    for (long long i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 
 
    MaxHeap minHeap(arr, n); 
    long long totalCost = 0; 
 
    while (minHeap.heap_siz1e() > 1) { 
 
         
        long long first = minHeap.extractMax(); 
        long long second = minHeap.extractMax(); 
        long long merged = abs(first - second);
        // cout<<first<<" "<<second<<endl;
        // cout<<merged<<endl;  
        minHeap.insertKey(merged); 
    } 
 
    minHeap.print();
 
    delete[] arr; 
    return 0; 
}