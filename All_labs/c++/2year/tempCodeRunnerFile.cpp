#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Функция для вычисления хеша строки с использованием rolling hash
unsigned long long hash_rolling(const string &s, int p, int base) {
    unsigned long long h = 0;
    for (char c : s) {
        h = (h * base + c) % p;
    }
    return h;
}

// Функция Рабина-Карпа для проверки наличия подстроки во всех текстах
bool rabin_karp(const string &text, const string &pattern, int p, int base, unsigned long long target_hash) {
    int n = text.length();
    int m = pattern.length();
    if (m > n) return false;

    unsigned long long hash_i = hash_rolling(text.substr(0, m), p, base);
    unsigned long long pow_m = 1;

    // Вычисляем base^(m-1) для дальнейшего использования
    for (int i = 1; i < m; i++) {
        pow_m = (pow_m * base) % p;
    }

    if (hash_i == target_hash && text.compare(0, m, pattern) == 0) {
        return true;
    }

    // Проверяем остальные окна
    for (int i = m; i < n; i++) {
        hash_i = (hash_i + p - (text[i - m] * pow_m) % p) % p;
        hash_i = (hash_i * base + text[i]) % p;

        if (hash_i == target_hash && text.compare(i - m + 1, m, pattern) == 0) {
            return true;
        }
    }

    return false;
}

string find_longest_common_substring(const vector<string> &strings, int p) {
    string minstring = *min_element(strings.begin(), strings.end(),
                                    [](const string &a, const string &b) {
                                        return a.size() < b.size();
                                    });
    int base = 128;

    for (int len = minstring.size(); len > 0; len--) {
        unordered_set<unsigned long long> checked_hashes;

        for (int start = 0; start <= minstring.size() - len; start++) {
            string substring = minstring.substr(start, len);
            unsigned long long target_hash = hash_rolling(substring, p, base);

            if (checked_hashes.count(target_hash)) continue;
            checked_hashes.insert(target_hash);

            bool found_in_all = true;
            for (const string &s : strings) {
                if (!rabin_karp(s, substring, p, base, target_hash)) {
                    found_in_all = false;
                    break;
                }
            }

            if (found_in_all) {
                return substring;
            }
        }
    }

    return ""; // если общая подстрока не найдена
}

int main() {
    unsigned long long p = 999999937;
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    string result = find_longest_common_substring(strings, p);
    cout << result << endl;

    return 0;
}
