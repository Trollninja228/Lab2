#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    long long int* content; // Массив для хранения элементов кучи
    long long int heap_size; // Текущий размер кучи
    long long int arr_size; // Максимальный размер массива
public:
    Heap(long long int* arr, long long int size) {
        content = new long long int[size];
        for (long long int i = 0; i < size; i++) {
            content[i] = arr[i];
        }
        heap_size = size;
        arr_size = size;
        buildMaxHeap(); // Строим кучу сразу при создании
    }

    ~Heap() {
        delete[] content; // Освобождаем память
    }

    void print() {
        for (long long int i = 0; i < heap_size; i++) {
            cout << content[i] << " ";
        }
        cout << endl;
    }

    long long int parent(long long int i) {
        return (i - 1) / 2; // Индекс родительского узла
    }

    long long int left(long long int i) {
        return (i * 2 + 1); // Индекс левого дочернего узла
    }

    long long int right(long long int i) {
        return (i * 2 + 2); // Индекс правого дочернего узла
    }

    void maxHeapify(long long int i) {
        long long int largest = i;
        long long int l = left(i);
        long long int r = right(i);

        if (l < heap_size && content[l] < content[largest]) {
            largest = l; // Находим наименьший элемент
        }
        if (r < heap_size && content[r] < content[largest]) {
            largest = r; // Находим наименьший элемент
        }

        if (largest != i) {
            swap(content[i], content[largest]); // Меняем местами
            maxHeapify(largest); // Рекурсивно восстанавливаем кучу
        }
    }

    void buildMaxHeap() {
        for (long long int i = (heap_size - 2) / 2; i >= 0; i--) {
            maxHeapify(i); // Восстанавливаем кучу для всех родительских узлов
        }
    }

    long long int extractMin() {
        // Извлекаем минимальный элемент (корень)
        if (heap_size < 1) {
            throw out_of_range("Heap is empty");
        }
        long long int minValue = content[0];
        content[0] = content[heap_size - 1]; // Ставим последний элемент на место корня
        heap_size--; // Уменьшаем размер кучи
        maxHeapify(0); // Восстанавливаем кучу
        return minValue; // Возвращаем минимальный элемент
    }

    void insert(long long int value) {
        // Добавляем новый элемент в кучу
        content[heap_size] = value; // Ставим элемент в конец
        heap_size++; // Увеличиваем размер кучи
        buildMaxHeap(); // Восстанавливаем кучу
    }

    long long int getHeapSize() {
        return heap_size; // Возвращаем текущий размер кучи
    }
};

int main() {
    long long int n;
    cin >> n; // Считываем количество массивов

    long long int* arr = new long long int[n]; // Создаём массив для хранения размеров массивов
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i]; // Считываем размеры массивов
    }

    Heap myHeap(arr, n); // Создаём кучу с размерами массивов
    long long int totalCost = 0; // Переменная для хранения общей стоимости

    // Пока в куче больше одного элемента
    while (myHeap.getHeapSize() > 1) {
        // Извлекаем два наименьших элемента
        long long int firstMin = myHeap.extractMin(); // Минимальный
        long long int secondMin = myHeap.extractMin(); // Второй минимальный

        // Считаем стоимость объединения
        long long int mergeCost = firstMin + secondMin;
        totalCost += mergeCost; // Добавляем к общей стоимости

        // Вставляем результат обратно в кучу
        myHeap.insert(mergeCost);
    }

    cout << totalCost; // Выводим общую стоимость

    delete[] arr; // Освобождаем память
    return 0;
}
