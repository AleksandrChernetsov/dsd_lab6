#include "SetLab5_Chernetsov.h"
#include <cstdlib>
#include <string>
#include <set>
#include <iterator>

namespace Lab5 {
    // F1: конструктор по умолчанию
    Set::Set() {}

    // Конструктор для создания множества (F5)
    // type = 'A' – чётные числа, 'B' – числа, кратные 6 (вариант 25)
    Set::Set(int n, int min, int max, char type) {
        if (n <= 0) return;

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

        if (first > last) return;

        int available = (last - first) / step + 1;
        if (available < n) n = available;

        while (elements.size() < (size_t)n) {
            int value = first + step * (std::rand() % available);
            F4(value);
        }
    }

    // Деструктор (F8)
    Set::~Set() {
        F8();
    }

    // F2: проверка на пустое множество
    bool Set::F2() const {
        return elements.empty();
    }

    // F3: проверка принадлежности элемента
    bool Set::F3(int value) const {
        return elements.find(value) != elements.end();
    }

    // F4: добавление элемента
    bool Set::F4(int value) {
        return elements.insert(value).second;
    }

    // F6: мощность множества
    int Set::F6() const {
        return static_cast<int>(elements.size());
    }

    // F7: строковое представление
    std::string Set::F7(char delimiter) const {
        if (F2()) return "";
        std::string result;

        for (std::set<int>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
            if (it != elements.begin()) result += delimiter;
            result += std::to_string(*it);
        }
        return result;
    }

    // F8: очистка памяти
    void Set::F8() {
        elements.clear();
    }

    // F9: подмножество
    bool Set::F9(const Set& other) const {
        for (int val : elements) {
            if (!other.F3(val)) return false;
        }
        return true;
    }

    // F10: равенство множеств
    bool Set::F10(const Set& other) const {
        return elements == other.elements;
    }

    // F11: объединение
    Set Set::F11(const Set& other) const {
        Set result = *this;
        result.elements.insert(other.elements.begin(), other.elements.end());
        return result;
    }

    // F12: пересечение
    Set Set::F12(const Set& other) const {
        Set result;
        for (int val : elements) {
            if (other.F3(val)) {
                result.F4(val);
            }
        }
        return result;
    }

    // F13: разность
    Set Set::F13(const Set& other) const {
        Set result;
        for (int val : elements) {
            if (!other.F3(val)) {
                result.F4(val);
            }
        }
        return result;
    }

    // F14: симметрическая разность
    Set Set::F14(const Set& other) const {
        Set u = this->F11(other);
        Set i = this->F12(other);
        return u.F13(i);
    }
}