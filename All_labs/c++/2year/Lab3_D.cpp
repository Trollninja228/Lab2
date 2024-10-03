#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_in_range(vector<int> &a, int l, int r) {
    return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        int count1 = count_in_range(a, l1, r1);
        int count2 = count_in_range(a, l2, r2);
        
        if (r1 >= l2 && r2 >= l1) {
            int overlap = count_in_range(a, max(l1, l2), min(r1, r2));
            cout << (count1 + count2 - overlap) << endl;
        } else {
            cout << (count1 + count2) << endl;
        }
    }
    
    return 0;
}
