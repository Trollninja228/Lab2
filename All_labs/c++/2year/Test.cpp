#include <iostream>
#include <vector>
#include <cmath>

const long long MOD = 1e9 + 7;  // Например, можно использовать это значение для модуля
const long long BASE = 31;  // Основание для хеширования

// Функция для вычисления степени по модулю
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long get_hash(const std::vector<long long>& hashes, int l, int r) {
    long long power = mod_pow(BASE, r - l, MOD);  // Вычисляем степень BASE
    return (hashes[r + 1] - hashes[l] * power) % MOD;
}

int main() {
    // Пример использования
    std::vector<long long> hashes = {0, 1, 2, 3, 4};  // Пример массива хешей
    int l = 1, r = 3;
    
    long long hash_value = get_hash(hashes, l, r);
    std::cout << "Hash value: " << hash_value << std::endl;
    
    return 0;
}
