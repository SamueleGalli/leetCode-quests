# Documentation

This repository contains a **Collection Of Programming Exercises** covering various **Difficulty Levels** and **Topics**, designed to strengthen my **Knowledge** and **Programming Skills**

Each exercise is labeled with its **Corresponding Topic**, which includes a brief explanation of the **Concepts And Techniques** involved in **Solving** the **Problem**

The exercises are taken from **LeetCode Questlines**, and I primarily solve them using **C++**

I aim to follow established **Programming Conventions** and **Best Practices** as closely as possible

## How to compile and run the program

You can compile the desired program using the following command:

```bash
c++ -g -Wall -Werror -Wextra the_program_to_execute.cpp -o your_custom_name && valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes -s ./your_custom_name
```

- **the_program_to_execute.cpp**: the source file you want to compile
- **your_custom_name**: the custom name you want to give to the executable
- _Replace these placeholders with the appropriate file name and executable name_

I also use **Valgrind** to ensure no leak occure

|        **FLAG**         | **EXPLANATION**                                      |
| :---------------------: | :--------------------------------------------------- |
|          `-g`           | Generates **Debugging Information**                  |
|         `-Wall`         | Enables _common_ **Compiler Warnings**               |
|        `-Wextra`        | Enables _additional_ **Compiler Warnings**           |
|        `-Werror`        | Treats **Warnings** as **Errors**                    |
|          `-o`           | Specifies the _output_ **Executable Name**           |
| `--show-leak-kinds=all` | Shows all _types_ of **Memory Leaks**                |
|   `--leak-check=full`   | Performs a _detailed_ **Memory Leak Check**          |
|  `--track-origins=yes`  | _Tracks_ the **Origins** of **Uninitialized Values** |
|          `-s`           | _Displays_ a **Summary** of **Detected Errors**      |

### CODING STYLE

In this **Project**, I mainly use using `namespace std;` for **Convenience**, to avoid repeatedly writing the `std::` _prefix_ and make **Coding Faster**
