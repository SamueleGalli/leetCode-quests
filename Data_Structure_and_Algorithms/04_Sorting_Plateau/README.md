# Sorting Plateau

- **Binary Search**
  - **Header**: `None`
  - An efficient search algorithm for **Sorted Arrays**
  - Repeatedly **Halves** the **Search Range** by comparing the target value with the **Middle Element**, achieving `O(log n)` _time complexity_

---

- **Counting Sort** - **Merge Sort** - **Quickselect**:
  - **Header**: `None`

  - **Counting Sort** - `sort`:
    - **Find** the **Maximum Value** in the array
    - **Create** a **Counting Array** of size `maximum value + 1`, where each index represents a value
    - **Count** how many times each value appears
    - **Reconstruct** the `original array` in **Sorted Order**, repeating each value according to its count

    - _Time Complexity_: `O(n + k)`
    - _Space Complexity_: `O(k)`

  - **Merge Sort** - `sort`:
    - **Recursively** divide the array into **Halves** until **Single Elements** are reached
    - **Merge** the portions back together in sorted order

    - _Time Complexity_: `O(n log n)`
    - _Space Complexity_: `O(n)`

  - **Quickselect** - `find`:
    - Select a **Pivot**
    - Partition the array by comparing elements with the **Pivot** and using `swap()` to move **Smaller Elements** to the `left` and **Larger Elements** to the `right`
    - Check the **Pivot Position** to determine which portion contains the **Target Position**
    - Continue only on that portion until the **Target Element** is found

    - _Time Complexity_:
      - _Average Case_: `O(n)`
      - _Worst Case_: `O(n²)`

---

- **Divide and Conquer**
  - A **Problem-Solving Technique** that divides a problem into smaller **Subproblems**, solves them `usually recursively` until **Base Cases** are reached, and uses their results to solve the **Original Problem**

---

## LAMBDA

- **Lambda Expression**
  - **Header**: `None`
  - **Anonymous Function** used to **Customize** existing algorithms

  - **Predicate functions** - A function that returns a `bool` value:
    - `Return true` → the condition is satisfied
    - `Return false` → the condition is not satisfied

  - **Comparator Function** - Used in sorting algorithms such as **std::sort**:
    - `Return true` → the first element should come before the second - **no Swap**
    - `Return false` → the first element should not come before the second - **Swap/Reorder**
  - The algorithm handles the **reordering** of elements

  ```cpp
  [Capture](parameters) -> return_type
  {
      body
  };

  //Ascending order
  std::sort(values.begin(), values.end(),
  [](int a, int b)
  {
      return a < b;
  });

  //Descending order
  std::sort(values.begin(), values.end(),
  [](int a, int b)
  {
      return a > b;
  });
  ```

| **Capture** | **Meaning**                                       |
| :---------- | :------------------------------------------------ |
| `[]`        | Captures nothing                                  |
| `[x]`       | Captures x by value                               |
| `[&x]`      | Captures x by reference                           |
| `[=]`       | Captures all used external variables by value     |
| `[&]`       | Captures all used external variables by reference |
| `[=, &x]`   | Captures all by value, except x by reference      |
| `[&, x]`    | Captures all by reference, except x by value      |

| **Component**    | **Meaning**                                     |
| :--------------- | :---------------------------------------------- |
| `Parameters`     | Values passed to the lambda                     |
| `-> return_type` | Optionally specifies the return type explicitly |
| `Body`           | Contains the code executed by the lambda        |

---

### Basic Function

- `sort(v.begin(), v.end())`
  - **Header**: `<algorithm>`

  - Sorts the **Elements** of `vector v` in:
    - `sort(v.begin(), v.end())`: **Ascending Order** - **Default Behavior**
    - `sort(v.begin(), v.end(), less<int>())`: **Explicit Ascending Order**
    - `sort(v.begin(), v.end(), greater<int>())`: **Descending Order**
    - `sort(v.begin(), v.end(), lambda)`: **Custom Order** using a `Lambda Expression`
  - _Time Complexity_: `O(n log n)`

---

|              **FUNCTION**              |  **LIBRARY**  | **DEFINITION**                                                                                        |
| :------------------------------------: | :-----------: | :---------------------------------------------------------------------------------------------------- |
|            `reserve(size)`             |    `None`     | Reserve enough **Capacity** for the specified number of elements without changing the **vector Size** |
|             `sqrt(value)`              |   `<cmath>`   | Calculate the **Square Root** of a `value`                                                            |
|         `srand(time(nullptr))`         | `<iostream>`  | itialize the **Random Number Generator** using the **Current Time** as the `seed`                     |
|                `rand()`                | `<iostream>`  | Generate a **Pseudo-Random Number**                                                                   |
|              `swap(a, b)`              | `<iostream>`  | Exchange the values of two variables                                                                  |
|    `copy(first, last, destination)`    | `<algorithm>` | Copy **Elements** from a specified **Range** to a **Destination**                                     |
|   `lower_bound(first, last, value)`    | `<algorithm>` | Return an **Iterator** to the **First Element Greater Than or Equal to Value**                        |
| `min_element/max_element(first, last)` | `<algorithm>` | Return an **Iterator** to the **Smallest/Larger Element** in the specified range                      |
