#include <iostream>
#include <vector>
using namespace std;

int main() {
    BST b;
    int n;
    cin >> n;
    int el;

    for (int i = 0; i < n; i++) {
        cin >> el;
        b.insert(el);
    }

    vector<pair<int, int>> v;
    v = b.calc_sum();
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << " ";
    }
    return 0;
}
