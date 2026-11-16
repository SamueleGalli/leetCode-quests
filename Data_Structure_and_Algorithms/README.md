# Documentation

This is a collection of exercises covering various difficulties and topics
created to strengthen my knowledge and **programming skills**

Each exercise is also labeled with its corresponding subject/topic
Each topic has a short explanation of the concepts used and the subject of the problem

The exercises are taken from LeetCode Questlines, and I primarily solve them in **C++**
I try to follow the programming style and best practices as closely as possible

## How to compile and run the program

You can compile and run the program using the following command:

```bash
c++ -g -Wall -Werror -Wextra -std=c++98 the_program_to_execute.cpp -o your_custom_name && valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes -s ./your_custom_name
```

- **the_program_to_execute.cpp**: the source file you want to compile.
- **your_custom_name**: the custom name you want to give to the executable.

Replace these placeholders with the appropriate file name and executable name.

---

**Extra**:

- **Lambda**: Anonymous function used to customize existing algorithms
  - **Predicate functions**:
    - `Return true`  → the condition is satisfied
    - `Return false` → the condition is not satisfied
    - **Comparator Function** - In sorting algorithms such as **std::sort**:
      - `Return true`  → the first element should come before the second**no swap**
      - `Return false` → the first element should not come before the second **Swap**
      - `The algorithm may then reorder/swap the elements)`

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
    };

    //Descending order
    std::sort(values.begin(), values.end(),
    [](int a, int b)
    {
        return a > b;
    };
    ```

    | **Capture** | **Meaning** |
    | :--- | :--- |
    | [] | Captures nothing |
    | [x] | Captures x by value |
    | [&x] | Captures x by reference |
    | [=] | Captures all used external variables by value |
    | [&] | Captures all used external variables by reference |
    | [=, &x] | Captures all by value, except x by reference |
    | [&, x] | Captures all by reference, except x by value |

    | **Component** | **Meaning** |
    | :--- | :--- |
    | Parameters | Values passed to the lambda |
    | -> return_type | Specifies the return type explicitly |
    | Body | Contains the code executed by the lambda |
