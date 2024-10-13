#include <iostream>
#include <queue>
#include <string>

using namespace std;

class CookieManager {
private:
    priority_queue<long long, vector<long long>, greater<long long> > minHeap;
    int maxBoxes;

public:
    CookieManager(int k) : maxBoxes(k) {}

    void insert(long long n) {
        if (minHeap.size() < maxBoxes) {
            minHeap.push(n);
        } else if (n > minHeap.top()) {
            minHeap.pop();
            minHeap.push(n);
        }
    }

    long long getMaxSum() {
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<long long> > tempHeap = minHeap;
        while (!tempHeap.empty()) {
            sum += tempHeap.top();
            tempHeap.pop();
        }
        return sum;
    }
};

int main() {
    int q, k;
    cin >> q >> k;
    CookieManager cookieManager(k);
    string command;
    long long n;

    for (int i = 0; i < q; ++i) {
        cin >> command;
        if (command == "print") {
            cout << cookieManager.getMaxSum() << endl;
        } else if (command == "insert") {
            cin >> n;
            cookieManager.insert(n);
        }
    }

    return 0;
}
