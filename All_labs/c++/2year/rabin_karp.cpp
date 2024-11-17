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

    if (hash_i == target_hash && text.compare(0, m, pattern) == 0) {
        positions.push_back(0);
        positions.push_back(m);
    }

    for (int i = 1; i <= n - m; i++) {
        hash_i = (hash_i - (text[i - 1] * pow_m) % p + p) % p;
        hash_i = (hash_i * 128 + text[i + m - 1]) % p;

        if (hash_i == target_hash && text.compare(i, m, pattern) == 0) {
            positions.push_back(i);
            positions.push_back(m);
        }
    }

    return positions;
}