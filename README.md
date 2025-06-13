# 🧮 Dynamic Array in C

This project implements a fully functional **dynamic array** in C, built from scratch without relying on any external libraries. It supports operations like resizing, inserting, deleting, searching, and more — similar to `std::vector` in C++ or Python's `list`.

> ✍️ Author: **Santhosh T K**  
> 📅 Created: **12 Sep 2023**

---

## 📦 Features

- Dynamic expansion and shrinking of the array size
- `push()` and `pop()` operations
- Insert at any position
- Delete by value
- Linear search
- Memory-efficient resizing
- Amortized performance similar to high-level dynamic arrays

---

## 🧠 Design Intuition

While working with C, I realized how limited static arrays are in terms of flexibility. So, I decided to build my own resizable array.

Why doubling and halving?
- **Doubling:** Keeps push operation amortized O(1), avoiding frequent reallocations.
- **Shrinking:** Saves memory when many elements are popped or deleted.
- **Minimum size limit:** Prevents constant resizing back and forth for small arrays (min size is set to 10).

This helped me understand dynamic memory management and data structures better, and gave me hands-on experience designing low-level components.

---

## 🛠 Usage

### 1. Include the Header

```c
#include "dynamic_array.h"
````

### 2. Compile

```bash
gcc main.c dynamic_array.c -o main
```

### 3. Sample Program

```c
dynamic_array* arr = create_array();

push(10, arr);
push(20, arr);
insert(1, 15, arr);
delete(10, arr);

int index = search(20, arr);
printf("Found at index: %d\n", index);

free_array(arr);
```

---

## 🔍 API Reference

| Function                          | Description                             |
| --------------------------------- | --------------------------------------- |
| `create_array()`                  | Initializes a new dynamic array         |
| `push(int element, array*)`       | Appends an element at the end           |
| `pop(array*)`                     | Removes and returns the last element    |
| `insert(int pos, int el, array*)` | Inserts element at a specific index     |
| `search(int el, array*)`          | Returns index of first occurrence or -1 |
| `delete(int el, array*)`          | Deletes first occurrence of element     |
| `free_array(array*)`              | Frees allocated memory safely           |

---

## 🧪 Example Output

```bash
After pushing 15 elements:
10 20 30 40 50 60 70 80 90 100 110 120 130 140 150 

After insertions:
111 10 20 30 40 50 999 60 70 80 90 100 110 120 130 140 150 

Popping elements:
Popped: 150
Popped: 140
Popped: 130
Popped: 120
Popped: 110

Final array:
111 10 20 30 40 50 999 60 70 80 90 100 
```

---

## ⏱ Time Complexity

| Operation | Avg Time Complexity | Worst Case       |
| --------- | ------------------- | ---------------- |
| Push      | O(1) (amortized)    | O(n)             |
| Pop       | O(1)                | O(n) (if resize) |
| Insert    | O(n)                | O(n)             |
| Delete    | O(n)                | O(n)             |
| Search    | O(n)                | O(n)             |

---

## 📁 Project Structure

```
.
├── dynamic_array.h     # Header file with public API
├── dynamic_array.c     # Core implementation logic
└── main.c              # Example driver and test code
```

---

## 🧹 Memory Management

Memory is dynamically allocated and resized during runtime based on the current load factor. When calling `free_array()` or cleaning up, make sure to release memory manually to avoid leaks.

---

## 💡 Future Enhancements

* Bounds checking and error handling
* Unit tests using `assert.h`
* Performance benchmarks
* Custom allocators
* Thread-safe version

---

## ⚠️ Notes

* Resizing is triggered when array is full (expand) or less than half-used (shrink).
* The minimum capacity is **10**, so shrinking won’t go below this.
* No bounds checks are implemented in `insert()` or `delete()` — use carefully in production.

---

## 👨‍💻 Author

**Santhosh T K**
3rd year CSE student, passionate about low-level programming, backend systems, and software architecture.
💬 Exploring how to build real systems from the ground up.

---

## 🔖 License

This project is open for use, study, and improvement for **educational and non-commercial** purposes.
If you use or modify this, feel free to mention the original work.

---

## 🙌 Contributions

Want to add features or optimize performance? Fork the repo and submit a PR or just DM me with suggestions.

```
