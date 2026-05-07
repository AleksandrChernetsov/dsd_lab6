#ifndef SETLAB1_2_CHERNETSOV_H
#define SETLAB1_2_CHERNETSOV_H

#include <string>

namespace Lab1_2 {
    // Структура узла односвязного списка
    struct Node {
        int data;
        Node* next;
    };

    // F1. Создание пустого множества
    Node* F1();

    // F2. Проверка на пустое множество
    bool F2(Node* head);

    // F3. Проверка принадлежности элемента множеству
    bool F3(Node* head, int value);

    // F4. Добавление нового элемента в начало списка
    Node* F4(Node* head, int value);

    // F5. Создание множества заданной мощности из случайных чисел
    Node* F5(int n, int min, int max, char type);

    // F6. Мощность множества
    int F6(Node* head);

    // F7. Строковое представление множества
    std::string F7(Node* head, char delimiter);

    // F8. Удаление множества (освобождение памяти)
    Node* F8(Node* head);

    // F9. Проверка, является ли множество A подмножеством B
    bool F9(Node* A, Node* B);

    // F10. Проверка равенства множеств A и B
    bool F10(Node* A, Node* B);

    // F11. Объединение множеств A и B
    Node* F11(Node* A, Node* B);

    // F12. Пересечение множеств A и B
    Node* F12(Node* A, Node* B);

    // F13. Разность множеств A - B
    Node* F13(Node* A, Node* B);

    // F14. Симметричная разность множеств A и B
    Node* F14(Node* A, Node* B);
}

#endif