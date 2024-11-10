#include <iostream> 
#include <vector> 
#include <string> 
#include <unordered_set> 
#include <algorithm> // Для min_element 
 
using namespace std; 
 
// Функция для вычисления хеша строки 
unsigned long long hash_rolling(const string &s, int p, int base) { 
    unsigned long long h = 0; 
    for (char c : s) { 
        h = (h * base + c) % p; 
    } 
    return h; 
} 
 
// Функция Рабина-Карпа, проверяющая наличие подстроки во всех текстах 
bool rabin_karp(const vector<string> &strings, const string &pattern, int p, int base) { 
    unsigned long long target_hash = hash_rolling(pattern, p, base); 
    int m = pattern.size(); 
    unsigned long long pow_m = 1; 
     
    for (int i = 1; i < m; i++) { 
        pow_m = (pow_m * base) % p; 
    } 
 
    // Проверяем наличие `pattern` в каждом из текстов 
    for (const string &text : strings) { 
        int n = text.size(); 
        if (m > n) return false; 
 
        unsigned long long hash_i = hash_rolling(text.substr(0, m), p, base); 
         
        // Сравнение хешей и подстрок 
        if (hash_i == target_hash && text.compare(0, m, pattern) == 0) { 
            continue; 
        } 
 
        bool found = false; 
        for (int i = m; i < n; i++) { 
            hash_i = (hash_i + p - (text[i - m] * pow_m) % p) % p; 
            hash_i = (hash_i * base + text[i]) % p; 
 
            if (hash_i == target_hash && text.compare(i - m + 1, m, pattern) == 0) { 
                found = true; 
                break; 
            } 
        } 
 
        if (!found) return false; 
    } 
 
    return true; 
} 
 
// Функция для поиска наибольшей общей подстроки с использованием бинарного поиска 
string find_longest_common_substring(const vector<string> &strings, int p) { 
    string minstring = *min_element(strings.begin(), strings.end(),  
                                    [](const string &a, const string &b) { 
                                        return a.size() < b.size(); 
                                    }); 
 
    int left = 0, right = minstring.size(); 
    int base = 128; 
    string best_substring = ""; 
 
    while (left <= right) { 
        int mid = (left + right) / 2; 
        bool found = false; 
        unordered_set<string> substrings; 
 
        // Создаем хеши для всех подстрок длины `mid` в `minstring` 
        for (int start = 0; start <= minstring.size() - mid; start++) { 
            string substring = minstring.substr(start, mid); 
            if (substrings.find(substring) == substrings.end()) { 
                substrings.insert(substring); 
                 
                // Проверяем, входит ли эта подстрока во все строки 
                if (rabin_karp(strings, substring, p, base)) { 
                    found = true; 
                    best_substring = substring; 
                    break; 
                } 
            } 
        } 
 
        if (found) { 
            left = mid + 1;  // Увеличиваем длину подстроки 
        } else { 
            right = mid - 1; // Уменьшаем длину подстроки 
        } 
    } 
 
    return best_substring; 
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