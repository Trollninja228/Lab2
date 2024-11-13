#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//written by n-n06;

int hash_rolling(const string &s, int p) {
    int h = 0;
    int pow = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        h = (h + s[i] * pow) % p;
        pow = (pow * 128) % p;
    }
    return h;
}

vector<int> rabin_karp(const string &text, const string &pattern, int p) {
    int n = text.length();
    int m = pattern.length();

    vector<int> positions;
    if (m > n) return positions;

    int target_hash = hash_rolling(pattern, p);
    int hash_i = hash_rolling(text.substr(0, m), p);
    int pow_m = 1;

    for (int i = 1; i < m; i++) {
        pow_m = (pow_m * 128) % p;
    }

    if (hash_i == target_hash && text.substr(0, m) == pattern) {
        positions.push_back(0);
        positions.push_back(m);
    }

    for (int i = 1; i <= n - m; i++) {
        hash_i = (hash_i - (text[i - 1] * pow_m) % p + p) % p;
        hash_i = (hash_i * 128) % p;
        hash_i = (hash_i + text[i + m - 1]) % p;

        if (hash_i == target_hash && text.substr(i, m) == pattern) {
            positions.push_back(i);
            positions.push_back(m);
        }
    }

    return positions;
}

int main() {
    int p = 5003;
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> v(n);
    vector<vector<int>> v1(n);
    vector<int> v2(s.size(), 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v1[i] = rabin_karp(s, v[i], p);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v1[i].size(); j += 2) {
            for (int k = v1[i][j]; k < v1[i][j] + v1[i][j + 1]; k++) {
                v2[k] = 1;
            }
        }
    }

    sort(v2.begin(),v2.end());
    if (v2[0]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}