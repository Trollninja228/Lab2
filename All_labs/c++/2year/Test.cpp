#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    } else {
        return a < b;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();  // Игнорируем символ новой строки после ввода числа
    vector<vector<string>> arr(n);
    
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        string temp;
        
        for (char c : s) {
            if (c != ' ') {
                temp += c;  // Собираем слово
            } else {
                if (!temp.empty()) {
                    arr[i].push_back(temp);  // Добавляем слово в вектор
                    temp.clear();  // Очищаем временную строку
                }
            }
        }
        if (!temp.empty()) {
            arr[i].push_back(temp);  // Добавляем последнее слово
        }
    }

    for (int i = 0; i < n; i++) {
        sort(arr[i].begin(), arr[i].end(), compare);  // Сортируем слова
    }

    // Формируем выходные строки
    for (int i = 0; i < n; i++) {
        for (const auto &word : arr[i]) {
            cout << word << " ";  // Выводим каждое слово
        }
        cout << endl;  // Переход на новую строку после каждого вектора
    }

    return 0;
}
