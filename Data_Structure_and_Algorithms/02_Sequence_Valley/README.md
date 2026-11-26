# Sequence Valley

- **Queue**
  - There are various type:
    - **Standard Queue** - `queue<type>`
      - **Header** - `<queue>`
      - A **FIFO** - `First-In, First-Out` data structure where elements are added to the **Back** and removed from the **Front**

      - Available operations:
        - `push(value)`: Insert a **Value** at the **Back** of the `queue` - _Time Complexity_: `O(1)`
        - `pop()`: Remove the **First Element** from the `queue` without returning it - _Time Complexity_: `O(1)`
        - `front()`: Access the **First Element** without removing it - _Time Complexity_: `O(1)`
        - `back()`: Access the **Last Element** without removing it - _Time Complexity_: `O(1)`

    - **Deque** - `deque<type>`
      - **Header** - `<deque>`
      - A `Double-ended queue`: A queue that allows insertion and removal from **Both Ends**

      - Available operations:
        - `push_back(value)`: Insert a **Value** at the **Back** - _Time Complexity_: `O(1)`
        - `push_front(value)`: Insert the **Value** at the **Front** - _Time Complexity_: `O(1)`
        - `pop_back()`: Remove the **Last Element** - _Time Complexity_: `O(1)
        - `pop_front()`: Remove the **First Element** - _Time Complexity_: `O(1)
        - `front()`: Return the **First Element** - _Time Complexity_: `O(1)
        - `back()`: Return the **Last Element** - _Time Complexity_: `O(1)

    - **Priority Queue** - `priority_queue<type, vector<type>>`
      - **Header** - `<queue>`
      - A queue where elements are organized according to their **Priority**

      - The two main heap types are:
        - **Max-Heap** - **Default**: The **Largest Element** is always at the top - `priority_queue<type, vector<type>, less<type>>`
        - **Min-Heap**: The **Smallest Element** is always at the top - `std::priority_queue<type, vector<type>, greater<type>>`

      - Available operations:
        - `push(value)`: Insert a **Value** into the `priority_queue` while maintaining the priority order - _Time Complexity_: `O(log n)`
        - `pop()`: Remove the **Top Element** without returning it - _Time Complexity_: `O(log n)`
        - `top()`: Access the **Top Element** without removing it - _Time Complexity_: `O(1)`

    - _Note_: Always check `empty()` before accessing or removing elements

---

- **Pair**
  - **Header** - `None`
  - A **Utility Class** that **Groups** two elements, potentially of **Different Types**, into a **Single Object**
  - The **Elements** are accessed through `first and second`

  - **Declaration Example**:

```cpp
  pair<type1, type2> variable = {value1, value2};
```

- _Time Complexity_: `O(1)` for element access - **First** and **Second**
- _Space Complexity_: `O(1)` for a **Fixed Pair** of elements.

---

## Struct

- **Struct**
  - Like a `class`, it is a **User-Defined Type** that groups **Data** and **Functions** together

  - Main differences from a `class`:
    - Members are **public** by default, instead of **private**
    - Inheritance is **public** by default, instead of **private**

---

- **Inheritance**:
  - Allows a **Derived Class** to inherit **Members** and **Functions** from a **Base Class**, enabling **Code Reuse** and **Specialization**

  - **Related Concepts**:
    - `protected`: Accessible within the `class`, its `friends` and **Derived Classes**
    - `friends`: Grants a specific `function` or `class` access to the **private** and **protected** members

  - **Inheritance Access Specifiers** - `DerivedClass : specifier BaseClass`:
    - `public`: `Public` members remain `public`, while `protected` members remain `protected`
    - `protected`: `Public` and `protected` members become `protected`
    - `private`: `Public` and protected members become `private`

### Basic Function

|           **FUNCTION**           |  **LIBRARY**  | **DEFINITION**                                                                 |
| :------------------------------: | :-----------: | :----------------------------------------------------------------------------- |
|         `isupper(value)`         | `<iostream>`  | Check whether **Value** is an uppercase `character`                            |
|   `reverse(v.begin(),v.end())`   | `<algorithm>` | **Reverse** the elements in the specified **Range**, modifying it **in place** |
|   `string(number, character)`    |  `<string>`   | Create a `string` by **Repeating Character** the specified number of **Times** |
| `find(v.being(),v.end(), value)` | `<algorithm>` | Search for **Value** in the specified **Range**                                |
|     `s.append(other_string)`     |  `<string>`   | **Append** another `string` to the end of a `string`                           |
|    `s.substring(pos, lenght)`    |  `<string>`   | Return a **Substring** starting at `pos` with the specified `length`           |
|      `min/max(num1, num2)`       | `<algorithm>` | Return the `Maximum/Minimum` of the given **Values**                           |
|        `to_string(value)`        |  `<string>`   | Convert a **Numeric Value** into a `string`                                    |
