#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>
#include <windows.h>

// Подключение заголовочных файлов лаб 1-5
#include "SetLab1_2_Chernetsov.h"
#include "SetLab3_Chernetsov.h"
#include "SetLab4_Chernetsov.h"
#include "SetLab5_Chernetsov.h"

using namespace std;
using namespace std::chrono;

// Определение длины UTF-8 строки в символах
size_t utf8_length(const string& s) {
    size_t len = 0;
    const char* ptr = s.c_str();
    while (*ptr) {
        unsigned char c = *ptr;
        if (c < 0x80) ptr += 1;
        else if ((c & 0xE0) == 0xC0) ptr += 2;
        else if ((c & 0xF0) == 0xE0) ptr += 3;
        else if ((c & 0xF8) == 0xF0) ptr += 4;
        else ptr += 1;
        ++len;
    }
    return len;
}

// Центрирование строки в поле заданной ширины (в символах)
string center_utf8(const string& s, int width) {
    size_t len = utf8_length(s);
    if (len >= static_cast<size_t>(width)) return s;
    int left = (width - static_cast<int>(len)) / 2;
    int right = width - static_cast<int>(len) - left;
    return string(left, ' ') + s + string(right, ' ');
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    system("color F0");

    cout << "Чернецов А.М. 24ВП1. Лабораторная работа №6." << endl;

    int N;
    while (true) {
        cout << "Введите мощность множеств N (N >= 1000): ";
        if (!(cin >> N)) {
            cout << "Ошибка: введите целое число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (N < 1000) {
            cout << "Внимание: N должно быть не меньше 1000. Попробуйте снова." << endl;
        }
        else if (N > 5000) {
            cout << "Предупреждение: при N > 5000 операции на списках (Лаб 1-4) будут очень долгими." << endl;
            cout << "Вы уверены, что хотите продолжить? (y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') break;
        }
        else {
            break;
        }
    }

    // Диапазон значений: от 0 до 10N
    int minV = 0;
    int maxV = 10 * N;
    unsigned int seed = static_cast<unsigned int>(time(NULL));

    const int col_width = 20;
    const int name_width = 28;
    const int total_width = 1 + name_width + 1 + 4 * (col_width + 1);

    string headers[] = { "Операция", "Лаб 1-2 (Список)", "Лаб 3 (Класс)", "Лаб 4 (std::list)", "Лаб 5 (std::set)" };
    string rows[] = {
        "Создание A и B", "Мощность", "Подмножество A⊂A", "Подмножество B⊂A",
        "Равенство A=A", "Равенство B=A", "Объединение", "Пересечение",
        "Разность A-B", "Разность B-A", "Симм. разность"
    };

    auto print_line = [&]() { cout << setfill('-') << setw(total_width) << "" << setfill(' ') << endl; };

    print_line();
    cout << '|' << center_utf8(headers[0], name_width) << '|';
    for (int i = 1; i < 5; ++i) cout << center_utf8(headers[i], col_width) << '|';
    cout << endl;
    print_line();

    // 1. Создание
    cout << '|' << center_utf8(rows[0], name_width) << '|';
    high_resolution_clock::time_point start, end;

    // Замеры времени для создания (с фиксацией seed для идентичности данных)
    srand(seed);
    start = high_resolution_clock::now();
    Lab1_2::Node* A1 = Lab1_2::F5(N, minV, maxV, 'A');
    Lab1_2::Node* B1 = Lab1_2::F5(N, minV, maxV, 'B');
    end = high_resolution_clock::now();
    cout << center_utf8(to_string(duration_cast<microseconds>(end - start).count()), col_width) << '|';

    srand(seed);
    start = high_resolution_clock::now();
    Lab3::Set A3(N, minV, maxV, 'A'); Lab3::Set B3(N, minV, maxV, 'B');
    end = high_resolution_clock::now();
    cout << center_utf8(to_string(duration_cast<microseconds>(end - start).count()), col_width) << '|';

    srand(seed);
    start = high_resolution_clock::now();
    Lab4::Set A4(N, minV, maxV, 'A'); Lab4::Set B4(N, minV, maxV, 'B');
    end = high_resolution_clock::now();
    cout << center_utf8(to_string(duration_cast<microseconds>(end - start).count()), col_width) << '|';

    srand(seed);
    start = high_resolution_clock::now();
    Lab5::Set A5(N, minV, maxV, 'A'); Lab5::Set B5(N, minV, maxV, 'B');
    end = high_resolution_clock::now();
    cout << center_utf8(to_string(duration_cast<microseconds>(end - start).count()), col_width) << '|' << endl;
    print_line();

    // Макрос для замера остальных операций
#define MEASURE(idx, op1, op3, op4, op5) \
        cout << '|' << center_utf8(rows[idx], name_width) << '|'; \
        start = high_resolution_clock::now(); { op1; } end = high_resolution_clock::now(); \
        cout << center_utf8(to_string(duration_cast<microseconds>(end - start).count()), col_width) << '|'; \
        start = high_resolution_clock::now(); { op3; } end = high_resolution_clock::now(); \
        cout << center_utf8(to_string(duration_cast<microseconds>(end - start).count()), col_width) << '|'; \
        start = high_resolution_clock::now(); { op4; } end = high_resolution_clock::now(); \
        cout << center_utf8(to_string(duration_cast<microseconds>(end - start).count()), col_width) << '|'; \
        start = high_resolution_clock::now(); { op5; } end = high_resolution_clock::now(); \
        cout << center_utf8(to_string(duration_cast<microseconds>(end - start).count()), col_width) << '|' << endl; \
        print_line();

    // Операции измерения
    MEASURE(1, Lab1_2::F6(A1), A3.F6(), A4.F6(), A5.F6());              // Мощность множества A
    MEASURE(2, Lab1_2::F9(A1, A1), A3.F9(A3), A4.F9(A4), A5.F9(A5));    // Проверка подмножества: A включает в себя A
    MEASURE(3, Lab1_2::F9(B1, A1), B3.F9(A3), B4.F9(A4), B5.F9(A5));    // Проверка подмножества: включено ли B в A
    MEASURE(4, Lab1_2::F10(A1, A1), A3.F10(A3), A4.F10(A4), A5.F10(A5));// Проверка равенства: A равно A
    MEASURE(5, Lab1_2::F10(B1, A1), B3.F10(A3), B4.F10(A4), B5.F10(A5));// Проверка равенства: равно ли B множеству A
    MEASURE(6, Lab1_2::F8(Lab1_2::F11(A1, B1)), A3.F11(B3), A4.F11(B4), A5.F11(B5)); // Объединение A и B
    MEASURE(7, Lab1_2::F8(Lab1_2::F12(A1, B1)), A3.F12(B3), A4.F12(B4), A5.F12(B5)); // Пересечение A и B
    MEASURE(8, Lab1_2::F8(Lab1_2::F13(A1, B1)), A3.F13(B3), A4.F13(B4), A5.F13(B5)); // Разность A - B
    MEASURE(9, Lab1_2::F8(Lab1_2::F13(B1, A1)), B3.F13(A3), B4.F13(A4), B5.F13(A5)); // Разность B - A

    // Замер симметричной разности
    MEASURE(10,
        Lab1_2::Node * d1 = Lab1_2::F13(A1, B1); Lab1_2::Node * d2 = Lab1_2::F13(B1, A1); Lab1_2::F8(Lab1_2::F11(d1, d2)); Lab1_2::F8(d1); Lab1_2::F8(d2),
        A3.F13(B3).F11(B3.F13(A3)),
        A4.F13(B4).F11(B4.F13(A4)),
        A5.F13(B5).F11(B5.F13(A5))
    );

    // Очистка динамической памяти для Lab1_2
    Lab1_2::F8(A1); Lab1_2::F8(B1);

    cout << "\nРезультаты указаны в микросекундах" << endl;
    system("pause");
    return 0;
}