# Recursion Maze

- **Two_Pointers**
  - **Header**: `None`
  - A **Technique** that uses **Two Pointers** to traverse a **Data Structure**, such as an `array` or a `linked list`, efficiently

  - A common variation is called **Fast & Slow Pointers**:
    - **Slow**: Moves **One Step** at a time
    - **Fast**: Moves **Two Steps** at a time
  - This variation can be used to find the **Middle** of a **Linked List**

  ```mermaid
    flowchart LR
    A["SLOW & FAST=1"] --> B["2"] --> C["3"] --> D["4"] --> E["5"]

  ```

  ```mermaid
    flowchart LR
    A["1"] --> B["SLOW=2"] --> C["FAST=3"] --> D["4"] --> E["5"]
  ```

  ```mermaid
    flowchart LR
    A["1"] --> B["2"] --> C["SLOW=3"] --> D["4"] --> E["FAST=5"]
  ```

  - _Time Complexity_: `O(n)`
  - _Space Complexity_: `O(1)`

---

- **Unorderd_Set**
  - **Header**: `<unordered_set>`
  - A **Container** that stores **Unique Elements**, meaning that **duplicate Values** are **Not Allowed**
  - Unlike an `array` or a `vector`, an `unordered_set` does **Not Maintain** elements in a **Specific Order**
  - It uses **Hashing** to provide **Efficient Element Access**
  - **Avilable Operations**:
    - `insert(value)`: Inserts an **Element** if it does not already exist in the **Set**
    - `erease(value)`: Removes an **Element** from the **Set**
    - `count(value)`: Checks whether an **Element Exists** in the **Set** - returns `1` if it **Exists**, otherwise `0`
    - `contains(value)`: Checks whether an **Element Exists** in the **Set** - `returns true` if it **Exists**, otherwise `false` - `C++20`.
    - `find(value)`: **Searches** for an **Element** and returns an **Iterator** to it if **Found**, otherwise `end()`
  - _Time Complexity_:
  - _Average Case_: `O(1)`
  - _Worst Case_: `O(n)` - **Due To Hash Collisions**

---

- **Sliding Window**
  - A **Technique** that uses a **Range Of Consecutive Elements**, called a **Window**, that moves across an `array` or a `string` to process data efficiently
  - The **Window** moves by adjusting its boundaries, usually called **Left** and **Right**
  - Instead of recalculating the entire result at each step, the algorithm **Updates** it by **Adding Incoming Elements** and **Removing Outgoing Elements**
  - **Types**:
    - **Fixed Size Window**: The **Window** always maintains the **same size**
    - **Variable Size Window**: The **Window Expands** or **Shrinks** depending on a specific condition

  - _Time Complexity_: Typically `O(n)` - When each **Element** is processed at most a constant number of times

  ```mermaid
    flowchart LR
    A["1"] --> B["2"] --> C["3"] --> D["4"] --> E["5"]
    style A fill:#16A34A, color: #FFFFFF
    style B fill:#16A34A, color: #FFFFFF
    style C fill:#16A34A, color: #FFFFFF
  ```

  ```mermaid
    flowchart LR
    A["1"] --> B["2"] --> C["3"] --> D["4"] --> E["5"]
    style B fill:#16A34A, color: #FFFFFF
    style C fill:#16A34A, color: #FFFFFF
    style D fill:#16A34A, color: #FFFFFF
  ```

  ```mermaid
    flowchart LR
    A["1"] --> B["2"] --> C["3"] --> D["4"] --> E["5"]
    style C fill:#16A34A, color: #FFFFFF
    style D fill:#16A34A, color: #FFFFFF
    style E fill:#16A34A, color: #FFFFFF
  ```

---

- **Rolling Hash**
  - **Header**: `None`
  - A **Technique** that computes a **Hash Value** for a `string` or `numeric sequence` and efficiently **Updates** it when a `sliding window` moves, avoiding **Full Recomputation**

  **Hash Formula Example**:

  ```cpp
    hash_value = ((old_hash * hash_value) + value) % MOD;
  ```

  - _Time Complexity_: `O(1)` per **Update**, `O(k)` for initial **Hash Computation**

---

- **Backtracking**
  - **Header**: `None`
  - A **Recursive Technique** that explores potential **Solutions** and **Backtracks**, undoing previous choices whenever it determines that the current path **Cannot Lead** to a **Valid Solution**

  - _Time Complexity_: `O(b^d)` in the _Worst Case_
  - _Space Complexity_: `O(d)` for the **Recursion Stack**

## Basic Function

|   **FUNCTION**   | **LIBRARY** | **DEFINITION**                                                                               |
| :--------------: | :---------: | :------------------------------------------------------------------------------------------- |
| `isalpha(value)` |   `None`    | Checks whether a `character` is an **Alphabetic Letter**                                     |
| `isdigit(value)` |   `None`    | Checks whether a character is a decimal digit (0-9)                                          |
| `resize(vector)` | `<vector>`  | Changes the **Number Of Elements** in a `vector`, either **Ddding** or **Removing** elements |
