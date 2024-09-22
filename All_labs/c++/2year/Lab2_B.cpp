#include <iostream>
#include <string>
using namespace std;
// Структура узла (обычный узел, указывающий на следующее слово)
struct Node {
    string data;     // Слово
    Node* next;      // Указатель на следующий элемент
};

// Функция для создания списка из массива слов
Node* createList(string words[], int n) {
    if (n == 0) return nullptr;  // Если слов нет, список пустой
    
    Node* head = new Node();     // Создаем первый узел
    head->data = words[0];       // Первое слово
    head->next = nullptr;        // Пока что следующий элемент - пустой
    
    Node* current = head;        // Указатель на текущий узел
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node();  // Создаем новый узел
        newNode->data = words[i];    // Следующее слово
        newNode->next = nullptr;     // Пока что последний элемент
        
        current->next = newNode;     // Соединяем предыдущий узел с новым
        current = newNode;           // Двигаемся к новому узлу
    }
    return head;  // Возвращаем указатель на первый элемент списка
}

// Функция для вывода списка
void printList(Node* head) {
    Node* current = head;           // Указатель на текущий узел
    while (current != nullptr) {    // Пока не дошли до конца
        cout << current->data << " ";
        current = current->next;    // Переход к следующему элементу
    }
    cout << endl;
}

// Функция для циклического сдвига
Node* shift(Node* head, int N, int K) {
    if (!head || K == 0 || N == 0) return head;  // Если сдвиг не нужен

    Node* current = head;
    int count = 1;  // Начинаем с первого узла

    // Дойдём до конца списка, чтобы сделать его циклом
    while (current->next != nullptr) {
        current = current->next;
        count++;
    }
    
    // Соединяем конец с началом, чтобы получился круг
    current->next = head;
    
    // Найдём новый конец списка: после (N - K % N) шагов
    K = K % N;  // Чтобы избежать лишних сдвигов, если K больше N
    int stepsToNewTail = N - K;
    
    Node* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;  // Двигаемся до нового конца списка
    }
    
    // Новая голова списка - это элемент после нового хвоста
    Node* newHead = newTail->next;
    
    // Разрываем круг, чтобы список снова стал односвязным
    newTail->next = nullptr;
    
    return newHead;
}

int main() {
    // Пример 1: создаём список и сдвигаем
    int N = 5, K = 2;
    string words1[] = {"the", "show", "must", "go", "on"};
    
    Node* head1 = createList(words1, N);  // Создание списка
    head1 = shift(head1, N, K);  // Сдвиг на 2 позиции
    printList(head1);  // Ожидаемый вывод: "must go on the show"
    
    // Пример 2:
    N = 5, K = 3;
    string words2[] = {"another", "one", "bites", "the", "dust"};
    
    Node* head2 = createList(words2, N);  // Создание списка
    head2 = shift(head2, N, K);  // Сдвиг на 3 позиции
    printList(head2);  // Ожидаемый вывод: "the dust another one bites"
    
    return 0;
}
