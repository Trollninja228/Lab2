#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool compare(const string &a, const string &b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    } else {
        int sum1=0;
        int sum2=0;
        for (int i = 0; i < a.size(); i++){
            sum1+=int(a[i]);
        }
        for (int i = 0; i < b.size(); i++){
            sum2+=int(b[i]);
        }
        if(sum1!=sum2){
            return sum1<sum2;
        }else{
            return a<b;
        }
    }
}

int partition(int *arr, int beg, int end) {
    srand(time(NULL));
    int p = beg + rand() % (end - beg + 1);
    swap(arr[end], arr[p]);
    int i = beg - 1;
    for (int j = beg; j < end; j++) {
        if (arr[j] <= arr[end]) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[end], arr[i + 1]);
    return i + 1;
}

void quick_sort(int *arr, int beg, int end) {
    if (beg < end) {
        int p = partition(arr, beg, end);
        quick_sort(arr, beg, p - 1);
        quick_sort(arr, p + 1, end);
    }
}

int bin_search(int* arr, int beg, int end, int key) {
    if (beg > end) {
        return -1;
    }
    int mid = (beg + end) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    if (key < arr[mid]) {
        return bin_search(arr, beg, mid - 1, key);
    } else {
        return bin_search(arr, mid + 1, end, key);
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<string>> arr(n);
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        string temp = "";
        for (char c : s) {
            if (c != ' ') {
                temp += c;
            } else {
                if (!temp.empty()) {
                    arr[i].push_back(temp);
                    temp = "";
                }
            }
        }
        if (!temp.empty()) {
            arr[i].push_back(temp);
        }
    }
    for (int i = 0; i < n; i++) {
        sort(arr[i].begin(), arr[i].end(), compare);
    }
    for (int i = 0; i < n; i++) {
        for (const auto& word : arr[i]) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}