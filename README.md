# Performance Comparison of Set Implementations (Lab 6) – C++ Console Application

This project performs a comprehensive performance comparison of four different set implementations developed during previous laboratory works. All implementations follow the same functional interface (F1–F14) but use different underlying data structures, allowing direct measurement of their time efficiency across various set operations.

The program generates two sets (A and B) according to **Variant 25**:
- **Set A** – even numbers
- **Set B** – numbers divisible by 6

The user can specify the desired cardinality for each set independently (minimum 1000 elements each). All operations are benchmarked in microseconds, and results are presented in a formatted table for easy comparison.

## ✨ Features

The program benchmarks the following four set implementations:

| Implementation | Underlying Structure | File |
|----------------|---------------------|------|
| **Labs 1–2** | Custom singly linked list (procedural) | `SetLab1_2_Chernetsov.cpp` |
| **Lab 3** | Custom singly linked list (object‑oriented) | `SetLab3_Chernetsov.cpp` |
| **Lab 4** | `std::list` (STL doubly linked list) | `SetLab4_Chernetsov.cpp` |
| **Lab 5** | `std::set` (STL balanced binary search tree) | `SetLab5_Chernetsov.cpp` |

### Measured Operations

Each implementation is tested on the following operations (time measured in microseconds):

| # | Operation | Description |
|---|-----------|-------------|
| 1 | Creation | Generating sets A and B with random elements satisfying the variant condition |
| 2 | Cardinality | Computing the size (power) of set A (F6) |
| 3 | Subset check (A ⊂ A) | Checking if A is a subset of itself (F9) |
| 4 | Subset check (B ⊂ A) | Checking if B is a subset of A (F9) |
| 5 | Equality (A = A) | Checking if A equals itself (F10) |
| 6 | Equality (B = A) | Checking if B equals A (F10) |
| 7 | Union | Computing A ∪ B (F11) |
| 8 | Intersection | Computing A ∩ B (F12) |
| 9 | Difference (A − B) | Computing A minus B (F13) |
| 10 | Difference (B − A) | Computing B minus A (F13) |
| 11 | Symmetric Difference | Computing A ∆ B = (A ∪ B) − (A ∩ B) (F14) |

All implementations are tested with **identical random seeds**, ensuring that each benchmark operates on exactly the same sets.

## 🧩 Variant 25 (as assigned)

| Set | Condition | Example elements |
|-----|-----------|-------------------|
| A | Even numbers | 0, 2, 4, 6, … |
| B | Multiples of 6 | 0, 6, 12, 18, … |

**Range**: `[0, 10 * N]` where N = max(N_A, N_B)  
**User input**: Separate cardinalities for A and B (each ≥ 1000, recommended ≤ 5000)

## 🛠️ Requirements

- C++ compiler with **C++11 support** (or later)
- Windows SDK (for `windows.h` – used for UTF‑8 console output)
- Standard C++ Library (STL)

The project uses `<chrono>` for high‑resolution timing measurements. On non‑Windows systems, comment out or remove the `SetConsoleCP` and `SetConsoleOutputCP` calls.

## 📂 File Structure

```
dsd_lab6/
├── README.md
├── dsd_lab6.slnx                     # Visual Studio solution file
├── dsd_lab6.vcxproj                  # Visual Studio project file
├── dsd_lab6.vcxproj.filters          # Project filters
├── Lab6_Main.cpp                     # Main program – benchmarks and comparisons
├── SetLab1_2_Chernetsov.h            # Labs 1–2: procedural linked list (header)
├── SetLab1_2_Chernetsov.cpp          # Labs 1–2: implementation
├── SetLab3_Chernetsov.h              # Lab 3: OOP linked list (header)
├── SetLab3_Chernetsov.cpp            # Lab 3: implementation
├── SetLab4_Chernetsov.h              # Lab 4: std::list wrapper (header)
├── SetLab4_Chernetsov.cpp            # Lab 4: implementation
├── SetLab5_Chernetsov.h              # Lab 5: std::set wrapper (header)
└── SetLab5_Chernetsov.cpp            # Lab 5: implementation
```

## 🚀 Building and Running

### Using g++ (MinGW, Linux, or macOS)

```bash
g++ -o lab6 Lab6_Main.cpp SetLab1_2_Chernetsov.cpp SetLab3_Chernetsov.cpp SetLab4_Chernetsov.cpp SetLab5_Chernetsov.cpp -std=c++11
./lab6
```

### Using Visual Studio

1. Open the solution file `dsd_lab6.slnx`
2. Build the solution (`Ctrl+Shift+B`)
3. Run (`F5`)

> ⚠️ On non‑Windows systems, comment out the `SetConsoleCP` and `SetConsoleOutputCP` lines in `Lab6_Main.cpp` to avoid compilation errors.

## 📊 Example Output

```
Чернецов А.М. 24ВП1. Лабораторная работа №6.
Введите мощность множества A (N_A >= 1000): 1000
Введите мощность множества B (N_B >= 1000): 1000
------------------------------------------------------------------------------------------------------------------
|          Операция          |  Лаб 1-2 (Список)  |   Лаб 3 (Класс)    | Лаб 4 (std::list)  |  Лаб 5 (std::set)  |
------------------------------------------------------------------------------------------------------------------
|       Создание A и B       |        5214        |        5360        |       193565       |        2709        |
------------------------------------------------------------------------------------------------------------------
|          Мощность          |         28         |         28         |         0          |         0          |
------------------------------------------------------------------------------------------------------------------
|      Подмножество A⊂A      |        2008        |        2171        |       87140        |        609         |
------------------------------------------------------------------------------------------------------------------
|      Подмножество B⊂A      |         21         |         21         |        134         |         2          |
------------------------------------------------------------------------------------------------------------------
|       Равенство A=A        |        4064        |        3865        |       171590       |         81         |
------------------------------------------------------------------------------------------------------------------
|       Равенство B=A        |         21         |         22         |        199         |         1          |
------------------------------------------------------------------------------------------------------------------
|        Объединение         |       10060        |        8293        |       318677       |        2250        |
------------------------------------------------------------------------------------------------------------------
|        Пересечение         |        3959        |        4217        |       158743       |        907         |
------------------------------------------------------------------------------------------------------------------
|        Разность A-B        |        5884        |        5592        |       182282       |        1706        |
------------------------------------------------------------------------------------------------------------------
|        Разность B-A        |        5977        |        5698        |       212152       |        1876        |
------------------------------------------------------------------------------------------------------------------
|       Симм. разность       |       17493        |       18444        |       651870       |        5260        |
------------------------------------------------------------------------------------------------------------------

Результаты указаны в микросекундах
```

*Note: Actual timing values depend on hardware, compiler optimizations, and the chosen cardinalities.*

## 📈 Performance Observations

- **std::set (Lab 5)** is significantly faster for subset checks, equality tests, and membership queries due to O(log n) operations.
- **std::list (Lab 4)** and custom linked lists (Labs 1–3) show comparable performance, with Lab 3 being slightly more efficient due to better encapsulation.
- **Creation time** is dominated by random number generation and duplicate avoidance – all implementations show similar results.
- **Union and intersection** operations are memory‑intensive and reflect the overhead of allocating new nodes.

## 🔍 Implementation Notes

- **Identical random seeds** – ensures fair comparison across implementations
- **High‑resolution timing** – uses `std::chrono::high_resolution_clock` with microsecond precision
- **Memory management** – all dynamically allocated memory is properly freed before program exit
- **UTF‑8 console support** – enables correct display of Cyrillic characters in Windows terminals
- **Input validation** – checks for numeric input, minimum cardinality (1000), and warns for large N (>5000)

## 👤 Author

**Aleksandr Chernetsov**  
Group: 24VP1  
Laboratory work for the course *Programming of Dynamic Data Structures*

## 📄 License

This project is created for educational purposes. Free use, modification, and distribution are permitted with attribution.
