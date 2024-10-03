#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n); 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> prefix_sum(n);
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }

    for (int i = 0; i < k; i++) {
        int query;
        cin >> query;
        
        auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), query);
        cout << (it - prefix_sum.begin() + 1) << endl;
    }

    return 0;
}
