#include <iostream>
#include <climits>
using namespace std;

// Функция для слияния двух отсортированных частей массива
void merge(int *arr, int beg, int mid, int end) {
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    // Создаем временные массивы
    int *left = new int[n1 + 1];
    int *right = new int[n2 + 1];

    // Копируем данные в временные массивы
    for (int i = 0; i < n1; i++) {
        left[i] = arr[beg + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    // Добавляем "сентинельные" значения (INT_MAX)
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;

    // Индексы для слияния
    int i = 0, j = 0;
    for (int k = beg; k <= end; k++) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }

    // Освобождаем память
    delete[] left;
    delete[] right;
}

// Рекурсивная функция для сортировки слиянием
void mergeSort(int *arr, int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;

        // Сортируем первую и вторую половины
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);

        // Сливаем отсортированные части
        merge(arr, beg, mid, end);
    }
}

int main() {
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    mergeSort(arr, 0, n - 1);

    // Вывод отсортированного массива
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
