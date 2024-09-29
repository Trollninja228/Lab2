#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0, sum = 0, min_length = INT_MAX;

    for (int end = 0; end < n; end++) {
        sum += arr[end];
        while (sum >= k) {
            min_length = min(min_length, end - start + 1);
            sum -= arr[start];
            start++;
        }
    }

    cout << min_length << endl;
    return 0;
}
