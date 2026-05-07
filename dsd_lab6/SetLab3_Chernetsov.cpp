#include "SetLab3_Chernetsov.h"
#include <cstdlib>
#include <string>

namespace Lab3 {
    // F1: конструктор по умолчанию
    Set::Set() : head(nullptr) {}

    // Конструктор для создания множества (F5)
    Set::Set(int n, int min, int max, char type) : head(nullptr) {
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

        head = nullptr;
        int count = 0;
        while (count < n) {
            int value = first + step * (std::rand() % available);
            Node* temp = head;
            F4(value);
            if (head != temp)
                ++count;
        }
    }

    // Деструктор (F8)
    Set::~Set() {
        F8();
    }

    // F2: проверка на пустое множество
    bool Set::F2() const {
        return head == nullptr;
    }

    // F3: проверка принадлежности элемента
    bool Set::F3(int value) const {
        if (F2()) return false;
        Node* current = head;
        while (current) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    // F4: добавление элемента в начало
    void Set::F4(int value) {
        if (F3(value)) return;
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // F6: мощность множества
    int Set::F6() const {
        int count = 0;
        Node* current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    // F7: строковое представление с разделителем
    std::string Set::F7(char delimiter) const {
        if (F2()) return "";
        std::string result;
        Node* current = head;
        result += std::to_string(current->data);
        current = current->next;
        while (current) {
            result += delimiter;
            result += std::to_string(current->data);
            current = current->next;
        }
        return result;
    }

    // F8: очистка памяти
    void Set::F8() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // F9: подмножество
    bool Set::F9(const Set& other) const {
        if (F2()) return true;
        Node* current = head;
        while (current) {
            if (!other.F3(current->data)) return false;
            current = current->next;
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
        Node* current = head;
        while (current) {
            result.F4(current->data);
            current = current->next;
        }
        current = other.head;
        while (current) {
            result.F4(current->data);
            current = current->next;
        }
        return result;
    }

    // F12: пересечение
    Set Set::F12(const Set& other) const {
        Set result;
        Node* current = head;
        while (current) {
            if (other.F3(current->data)) {
                result.F4(current->data);
            }
            current = current->next;
        }
        return result;
    }

    // F13: разность
    Set Set::F13(const Set& other) const {
        Set result;
        Node* current = head;
        while (current) {
            if (!other.F3(current->data)) {
                result.F4(current->data);
            }
            current = current->next;
        }
        return result;
    }

    // F14: симметрическая разность (A ∆ B) = (A ∪ B) \ (A ∩ B)
    Set Set::F14(const Set& other) const {
        Set u = this->F11(other);
        Set i = this->F12(other);
        Set result = u.F13(i);
        return result;
    }
}