#ifndef SETLAB4_CHERNETSOV_H
#define SETLAB4_CHERNETSOV_H

#include <string>
#include <list>

namespace Lab4 {
    class Set {
    private:
        std::list<int> elements;

    public:
        // F1: конструктор по умолчанию (пустое множество)
        Set();

        // Конструктор для создания множества (F5)
        // type = 'A' – чётные числа, 'B' – числа, кратные 6 (вариант 25)
        Set(int n, int min, int max, char type);

        // F8: деструктор
        ~Set();

        // F2: проверка на пустое множество
        bool F2() const;

        // F3: проверка принадлежности элемента
        bool F3(int value) const;

        // F4: добавление нового элемента в начало списка
        void F4(int value);

        // F6: мощность множества
        int F6() const;

        // F7: строковое представление множества с разделителем
        std::string F7(char delimiter) const;

        // F8: очистка множества (освобождение памяти)
        void F8();

        // F9: является ли текущее множество подмножеством other
        bool F9(const Set& other) const;

        // F10: равенство двух множеств
        bool F10(const Set& other) const;

        // F11: объединение множеств
        Set F11(const Set& other) const;

        // F12: пересечение множеств
        Set F12(const Set& other) const;

        // F13: разность множеств
        Set F13(const Set& other) const;

        // F14: симметрическая разность
        Set F14(const Set& other) const;
    };
}

#endif