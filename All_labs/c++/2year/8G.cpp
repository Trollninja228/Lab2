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

int main() {
    int p = 5003;
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> v(2*n);
    vector<vector<int>> v1(n);
    string s1;
    int k=0;
    for (int i = 0; i < n; i++) {
        cin >> v[k]>> v[k+1];
        // cout<<"Test1 ";
        s1=s.substr(v[k]-1,v[k+1]-v[k]+1);
        // cout<<s1<<endl;
        v1[i] = rabin_karp(s, s1, p);
        k+=2;
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < v1[i].size(); j++){
    //         cout<<v1[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    for (int i = 0; i < n; i++) {
        cout<<v1[i].size()/2<<endl;
        
    }
    return 0;
}