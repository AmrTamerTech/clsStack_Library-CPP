# 🧱 clsStack_Library-cpp

A reusable and extensible C++ stack implementation (`clsMyStack`) built using a doubly linked list via inheritance from a queue class. This generic class supports core stack operations along with additional list-based manipulations.

---

## 🌟 Overview

The `clsMyStack` class extends `clsMyQueue<T>` and leverages a custom `clsDblLinkedList<T>` for efficient memory usage and flexible data handling. It implements **Last-In-First-Out (LIFO)** behavior and is templated to work with any data type.

---

## 🚀 Features

### ✅ Basic Stack Operations:
- `Push(T value)` → Adds a new element to the top of the stack.
- `Top()` → Returns the top (most recently added) element.
- `Bottom()` → Returns the bottom (least recently added) element.
- `Pop()` → Removes the top element (inherited from `clsMyQueue`).
- `Size()` → Returns number of elements.
- `IsEmpty()` → Checks if the stack is empty.
- `Clear()` → Clears all stack elements.
- `Print()` → Prints all elements in stack order.

### ✨ Advanced (Inherited) List Operations:
- `GetItem(index)`
- `UpdateItem(index, newValue)`
- `InsertAfter(index, value)`
- `InsertAtBack(value)` – Useful for queue-style operations.
- `Reverse()` – Reverses the entire stack.
- `InsertAtFront(value)` – Used by `Push()` to maintain LIFO.

---

## 🛠 Technologies Used

- **Language**: C++
- **Data Structure**: Doubly Linked List
- **Concepts**: Templates, Inheritance, OOP, Dynamic Memory

---

## 🔧 How to Run

1. **Clone the repository:**
```bash
git clone https://github.com/your-username/clsStack_Library-cpp.git
cd clsStack_Library-cpp
```
2. **Build your test file (e.g. main.cpp):**

```bash
g++ main.cpp -o stackApp
./stackApp
```
3. **Include in your project:**
```bash
#include "clsMyStack.h"
#include "clsMyQueue.h"
#include "clsDblLinkedList.h"
```
