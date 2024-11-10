#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
 
using namespace std; 
 
int hash_rolling(const string &s, int p) { 
    int h = 0; 
    int pow = 1; 
    for (int i = s.length() - 1; i >= 0; i--) { 
        h = (h + s[i] * pow) % p; 
        pow = (pow * 128) % p; 
    } 
    return h; 
} 
 
int rabin_karp(const string &text, const string &pattern, int p) { 
    int n = text.length(); 
    int m = pattern.length(); 
    int freq = 0; 
 
    int target_hash = hash_rolling(pattern, p); 
    int hash_i = hash_rolling(text.substr(0, m), p); 
    int pow_m = 1; 
 
    for (int i = 1; i < m; i++) { 
        pow_m = (pow_m * 128) % p; 
    } 
 
    if (hash_i == target_hash && text.substr(0, m) == pattern) { 
        freq++; 
    } 
 
    for (int i = 1; i <= n - m; i++) { 
        hash_i = (hash_i - (text[i - 1] * pow_m) % p + p) % p; 
        hash_i = (hash_i * 128) % p; 
        hash_i = (hash_i + text[i + m - 1]) % p; 
 
        if (hash_i == target_hash && text.substr(i, m) == pattern) { 
            freq++; 
        } 
    } 
 
    return freq; 
} 
 
int main() { 
    int p = 10000; 
    int n; 
    string s, text; 
    vector<string> templates; 
    vector<string> texts; 
    vector<int> nums; 
 
    while (true) { 
        cin >> n; 
        if (n == 0) { 
            break; 
        } 
 
        nums.push_back(n); 
 
        for (int i = 0; i < n; i++) { 
            cin >> s; 
            templates.push_back(s); 
        } 
        cin >> text; 
        texts.push_back(text); 
    } 
 
    int template_index = 0; 
    for (int l = 0; l < nums.size(); l++) { 
        int max_freq = 0; 
        vector<string> max_patterns; 
 
        for (int i = 0; i < nums[l]; i++) { 
            int freq = rabin_karp(texts[l], templates[template_index++], p); 
 
            if (freq > max_freq) { 
                max_freq = freq; 
                max_patterns.clear(); 
                max_patterns.push_back(templates[template_index - 1]); 
            } else if (freq == max_freq) { 
                max_patterns.push_back(templates[template_index - 1]); 
            } 
        } 
 
        cout << max_freq << endl; 
        for (const auto &pattern : max_patterns) { 
            cout << pattern << endl; 
        } 
    } 
 
    return 0; 
}