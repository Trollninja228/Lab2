#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

long long int hash_rolling(const string &s, long long int p, long long int m) {
    long long int h = 0;
    for (long long int i = 0; i < m; ++i) {
        h = (h * p + s[i]) % p;
    }
    return h;
}

vector<long long int> rabin_karp_positions(const string &text, const string &pattern, long long int p) {
    long long int n = text.length(), m = pattern.length();
    vector<long long int> positions;
    
    if (m > n) return positions;

    long long int target_hash = hash_rolling(pattern, p, m);
    long long int hash_i = hash_rolling(text, p, m);
    long long int pow_m = 1;

    for (long long int i = 1; i < m; ++i)
        pow_m = (pow_m * p) % p;

    if (hash_i == target_hash && text.compare(0, m, pattern) == 0)
        positions.push_back(0);

    for (long long int i = 1; i <= n - m; ++i) {
        hash_i = (hash_i - text[i - 1] * pow_m % p + p) % p;
        hash_i = (hash_i * p + text[i + m - 1]) % p;

        if (hash_i == target_hash && text.compare(i, m, pattern) == 0)
            positions.push_back(i);
    }

    return positions;
}

int main() {
    long long int p = 5003;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<long long int> v1 = rabin_karp_positions(s1, s3, p);
    vector<long long int> v2 = rabin_karp_positions(s2, s3, p);

    unordered_set<long long int> pos_set(v1.begin(), v1.end());
    int common_positions = 0;

    for (long long int pos : v2) {
        if (pos_set.find(pos) != pos_set.end()) {
            ++common_positions;
        }
    }
    cout << common_positions;
    return 0;
}
