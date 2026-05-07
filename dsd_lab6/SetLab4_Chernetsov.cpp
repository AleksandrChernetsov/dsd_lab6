#include "SetLab4_Chernetsov.h"
#include <cstdlib>
#include <string>
#include <list>
#include <algorithm>

namespace Lab4 {
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

        if (first > last) {
            last = first + step * 10;
        }

        int available = (last - first) / step + 1;
        if (available < n) n = available;

        int count = 0;
        while (count < n) {
            int value = first + step * (std::rand() % available);
            size_t oldSize = elements.size();
            F4(value);
            if (elements.size() > oldSize)
                ++count;
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
        for (std::list<int>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
            if (*it == value) return true;
        }
        return false;
    }

    // F4: добавление элемента в начало
    void Set::F4(int value) {
        if (F3(value)) return;
        elements.push_front(value);
    }

    // F6: мощность множества
    int Set::F6() const {
        return static_cast<int>(elements.size());
    }

    // F7: строковое представление
    std::string Set::F7(char delimiter) const {
        if (F2()) return "";
        std::string result;

        std::list<int>::const_iterator it = elements.begin();
        result += std::to_string(*it);
        ++it;

        while (it != elements.end()) {
            result += delimiter;
            result += std::to_string(*it);
            ++it;
        }
        return result;
    }

    // F8: очистка памяти
    void Set::F8() {
        elements.clear();
    }

    // F9: подмножество
    bool Set::F9(const Set& other) const {
        if (F2()) return true;
        for (std::list<int>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
            if (!other.F3(*it)) return false;
        }
        return true;
    }

    // F10: равенство множеств
    bool Set::F10(const Set& other) const {
        return F9(other) && other.F9(*this);
    }

    // F11: объединение
    Set Set::F11(const Set& other) const {
        Set result;
        for (std::list<int>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
            result.F4(*it);
        }
        for (std::list<int>::const_iterator it = other.elements.begin(); it != other.elements.end(); ++it) {
            result.F4(*it);
        }
        return result;
    }

    // F12: пересечение
    Set Set::F12(const Set& other) const {
        Set result;
        for (std::list<int>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
            if (other.F3(*it)) {
                result.F4(*it);
            }
        }
        return result;
    }

    // F13: разность
    Set Set::F13(const Set& other) const {
        Set result;
        for (std::list<int>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
            if (!other.F3(*it)) {
                result.F4(*it);
            }
        }
        return result;
    }

    // F14: симметрическая разность
    Set Set::F14(const Set& other) const {
        Set u = this->F11(other);
        Set i = this->F12(other);
        Set result = u.F13(i);
        return result;
    }
}