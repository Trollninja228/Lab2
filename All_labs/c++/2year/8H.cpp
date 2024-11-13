#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Функция для вычисления хеша строки
unsigned long long hash_rolling(const string &s, int p) {
    unsigned long long h = 0;
    int base = 128;
    for (char c : s) {
        h = (h * base + c) % p;
    }
    return h;
}

// Проверка, что подстрока заданной длины существует во всех строках
bool exists_in_all(const vector<string> &strings, const string &substring, int p) {
    for (const auto &text : strings) {
        if (text.find(substring) == string::npos) {
            return false;
        }
    }
    return true;
}

// Поиск самой длинной общей подстроки
string find_longest_common_substring(const vector<string> &strings, int p) {
    string minstring = *min_element(strings.begin(), strings.end(),
                                    [](const string &a, const string &b) {
                                        return a.size() < b.size();
                                    });
    int left = 1, right = minstring.size();
    string result = "";

    while (left <= right) {
        int mid = left + (right - left) / 2;
        bool found = false;
        unordered_set<string> substrings;

        // Формируем все подстроки длиной mid для минимальной строки
        for (int i = 0; i <= minstring.size() - mid; i++) {
            substrings.insert(minstring.substr(i, mid));
        }

        // Проверяем наличие каждой подстроки во всех строках
        for (const auto &sub : substrings) {
            if (exists_in_all(strings, sub, p)) {
                result = sub;
                found = true;
                break;
            }
        }

        if (found) {
            left = mid + 1;  // Пробуем увеличить длину подстроки
        } else {
            right = mid - 1;  // Пробуем уменьшить длину подстроки
        }
    }

    return result;
}

int main() {
    int p = 999999937;
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    string result = find_longest_common_substring(strings, p);
    cout << result << endl;

    ret