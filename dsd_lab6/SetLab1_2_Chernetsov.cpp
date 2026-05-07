#include "SetLab1_2_Chernetsov.h"
#include <cstdlib>

namespace Lab1_2 {
    // F1. Создание пустого множества
    Node* F1() {
        return nullptr;
    }

    // F2. Проверка на пустое множество
    bool F2(Node* head) {
        return head == nullptr;
    }

    // F3. Проверка принадлежности элемента множеству
    bool F3(Node* head, int value) {
        if (F2(head))
            return false;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    // F4. Добавление нового элемента в начало списка
    Node* F4(Node* head, int value) {
        if (F3(head, value))
            return head;
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        return newNode;
    }

    // F5. Создание множества заданной мощности из случайных чисел,
    //     удовлетворяющих условию для множества A или B (вариант 25)
    //     Для type = 'A' – только четные числа, для type = 'B' – только кратные 6.
    Node* F5(int n, int min, int max, char type) {
        if (n <= 0)
            return nullptr;

        int step = (type == 'A') ? 2 : 6;
        int first, last;

        if (type == 'A') {
            first = (min % 2 == 0) ? min : min + 1;
            last = (max % 2 == 0) ? max : max - 1;
        }
        else {
            first = (min % 6 == 0) ? min : min + (6 - min % 6);
            last = max - (max % 6);
        }

        if (first > last) {
            last = first + step * 10;
        }

        int available = (last - first) / step + 1;

        if (available < n) {
            n = available;
        }

        Node* head = F1();
        int count = 0;

        while (count < n) {
            int value = first + step * (std::rand() % available);
            Node* temp = head;
            head = F4(head, value);
            if (head != temp)
                ++count;
        }
        return head;
    }

    // F6. Мощность множества
    int F6(Node* head) {
        if (F2(head))
            return 0;
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
        return count;
    }

    // F7. Строковое представление множества с разделителем
    std::string F7(Node* head, char delimiter) {
        if (F2(head))
            return "";

        std::string result;
        Node* current = head;

        result += std::to_string(current->data);
        current = current->next;

        while (current != nullptr) {
            result += delimiter;
            result += std::to_string(current->data);
            current = current->next;
        }
        return result;
    }

    // F8. Удаление множества (освобождение памяти)
    Node* F8(Node* head) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        return nullptr;
    }

    // F9. Проверка, является ли множество A подмножеством B
    bool F9(Node* A, Node* B) {
        if (F2(A))
            return true;
        Node* current = A;
        while (current != nullptr) {
            if (!F3(B, current->data))
                return false;
            current = current->next;
        }
        return true;
    }

    // F10. Проверка равенства множеств A и B
    bool F10(Node* A, Node* B) {
        return F9(A, B) && F9(B, A);
    }

    // F11. Объединение множеств A и B
    Node* F11(Node* A, Node* B) {
        Node* result = nullptr;

        if (F2(A) && F2(B)) {
            return result;
        }

        Node* current = A;
        while (current != nullptr) {
            result = F4(result, current->data);
            current = current->next;
        }

        current = B;
        while (current != nullptr) {
            result = F4(result, current->data);
            current = current->next;
        }

        return result;
    }

    // F12. Пересечение множеств A и B
    Node* F12(Node* A, Node* B) {
        if (F2(A) || F2(B)) {
            return nullptr;
        }

        Node* result = nullptr;
        Node* current = A;

        while (current) {
            if (F3(B, current->data)) {
                result = F4(result, current->data);
            }
            current = current->next;
        }

        return result;
    }

    // F13. Разность множеств A - B
    Node* F13(Node* A, Node* B) {
        if (F2(A)) {
            return nullptr;
        }
        Node* result = nullptr;
        Node* current = A;
        while (current) {
            if (!F3(B, current->data)) {
                result = F4(result, current->data);
            }
            current = current->next;
        }
        return result;
    }

    // F14. Симметрическая разность множеств A ∆ B = (A-B) ∪ (B-A)
    Node* F14(Node* A, Node* B) {
        Node* unionAB = F11(A, B);
        Node* intersectAB = F12(A, B);
        Node* result = F13(unionAB, intersectAB);
        F8(unionAB);
        F8(intersectAB);
        return result;
    }
}