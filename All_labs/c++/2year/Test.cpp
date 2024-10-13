#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
int partition(long long int *arr, int beg, int end){
    srand(time(NULL));

    int p = beg+rand()%(end-beg);//beg--end

    swap(arr[end], arr[p]);

    int i = beg - 1;
    for(int j=beg;j<end;j++){
        if(arr[j]<=arr[end]){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[end],arr[i+1]);
    return i+1;
}
void quick_sort (long long int *arr, int beg, int end){
    if(beg<end){
        int p=partition(arr,beg,end);
        quick_sort(arr,beg,p-1);
        quick_sort(arr,p+1,end);
    }
    
}
class Heap {
private:
    long long* content;
    long long heap_size;
    long long arr_size;
public:
    Heap(long long size) {
        arr_size = size;
        heap_size = 0;
        content = new long long[arr_size];
        
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

    int extractMin() {
        
        long long root = content[0];
        content[0] = content[heap_size - 1];
        heap_size--;
        minHeapify(0);

        return root;
        
    }
    long long extractMax(int i) {
        long long root = content[i];
        // content[0] = content[heap_size - 1];
        // content[heap_size - 1] = root;

        // heap_size--;

        // maxHeapify(i);
        return root;
    }


    bool isEmpty() {
        return heap_size == 0;
    }

    int heap_siz1e(){
        return heap_size;
    }

    void print(){
        for(int i = 0; i < arr_size; i++){
            cout << content[i] << ' ';
        }
        
    }
    void start(){
        for (long long int i = 0; i < arr_size; i++)
        {
            content[i]=0;
        }
        
    }
    

    
    void insertKey(int key) {
        content[heap_size] = key;
        heap_size++;
        quick_sort(content,0,heap_size);
    }

    void printmax(int k){
        // int size = heap_size;
        long long totalsum = 0;

        for (int i = 0; i < k && heap_size > 0; i++) {
            
            long long int maxElem = extractMax(i);
            // cout << maxElem << endl;
            totalsum += maxElem;
        

        }
        // heap_size = size;

        cout << totalsum << endl;
        
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    int t;
    if (n>k){
        t=n;
    }else{
        t=k;
    }
    Heap myheap(t);
    string s; 
    int elem;
    myheap.start();
    // myheap.print();
    // vector<long long> res;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "print"){
            if(myheap.isEmpty()){
                // res.push_back(0);
                cout << 0 << endl;
            }
            else{
                // res.push_back(myheap.printmax(k));
                myheap.printmax(k);
            }
        }
        else{
            cin >> elem;
            myheap.insertKey(elem);
        }
    }

    myheap.print();
    
    return 0;
}