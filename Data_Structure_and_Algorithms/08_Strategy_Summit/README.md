# Stategy Summit

- **Greedy**
  - **Header**: `None`
  - An **Algorithmic Strategy** that selects the option that looks **Best At Each Step** - `Locally Optimal Choice`
  - The **Objective** is to reach the **Best Overall Solution** - `Globally Optimal Solution` through a sequence of **Local Decisions**
  - A **Greedy Approach** does not always guarantee the **Globally Optimal Solution**

  - **Example** - `Activity Selection`:
    - **Objective**: Select the **Maximum Number Of Activities** without **Overlapping**
    - **Strategy**: Always select the activity with the **Earliest Finish Time**

  | **ACTIVITY** | **START** | **END** |
  | :----------: | :-------: | :-----: |
  |     `A`      |    `1`    |   `3`   |
  |     `B`      |    `2`    |   `5`   |
  |     `C`      |    `4`    |   `6`   |
  |     `D`      |    `6`    |   `7`   |
  |     `E`      |    `5`    |   `9`   |
  
  - **Selected Activities**:
    - **A**: `1 - 3`
    - **C**: `4 - 6`
    - **D**: `6 - 7`
    - **Result**: `3` **Activities Selected**
  - _Time Complexity_: `O(n log n)` including **Sorting By Finish Time**, `O(n)` if **Already Sorted**
  - _Space Complexity_: `O(1)` **Auxiliary Space**, **Excluding** the **Input** and **Stored Result**

---

- **Dynamic Programming**
  - Solving a problem by **Dividing It** into **Smaller Subproblems** and **Saving Their Results** to **Avoid Recalculations**
  - It can use a **Memoization Structure** e.g. a `vector` to store **Calculated Results**

  - **Example** - `Fibonacci n = 6`:
    - `dp[0] = 0, dp[1] = 1`
    - Each value is **Calculated** using the **Two Previous Values**:
      - `dp[i] = dp[i - 1] + dp[i - 2]`
    - **Calculated Results**: `dp = {0, 1, 1, 2, 3, 5, 8}`
    - **Final Result**: `dp[6] = 8`
    - _Time Complexity_: `O(n)` - Each **Value** is **Calculated Once**
    - _Space Complexity_: `O(n)` - The `vector` **Stores** `n + 1 values`

---

- **2D Dynamic Programming**
  - The same as **Dynamic Programming**, but the `memo` has **Two Dimensions**, usually represented as `dp[i][j]`
  - Each **State** depends on **Two Variables**

  - **Example** - `0/1 Knapsack`:
    - Given a **Knapsack** with a **Maximum Capacity** of `2` and the **Following Items**:

    | **ITEM INDEX** | **WEIGHT** | **VALUE** |
    | :------------: | :--------: | :-------: |
    |      `1`       |    `1`     |    `2`    |
    |      `2`       |    `2`     |    `3`    |

    - The **Objective** is to find the **Maximum Total Value** without **Exceeding** the **Knapsack Capacity**
    - `dp[i][w]`: represents the **Maximum Total Value Obtainable** using the **First** `i` **Items** with **Capacity** `w`
    - **DP Matrix**:

    | **ITEMS/CAPACITY** | `0` | `1` | `2` |
    | :----------------: | :-: | :-: | :-: |
    |     `0 items`      | `0` | `0` | `0` |
    |     `1 items`      | `0` | `2` | `2` |
    |     `2 items`      | `0` | `2` | `3` |

    - **Partial Calculations**:
      - `dp[1][1] = max(0,2) = 2` - **Take Item 1**
      - `dp[1][2] = max(0, 2) = 2` - **Take Item 1**
      - `dp[2][1] = dp[1][1] = 2` - **Item 2 Does Not Fit**
      - `dp[2][2] = max(dp[1][2], dp[1][0] + 3) = max(2, 3) = 3` - **Take Item 2**

    - **Index Explanation**:
      - `i`: represents the **Number of Items Considered** - `Rows` , not a **Single Item Index**
      - `dp[0][w]`: **No Items Considered**
      - `dp[1][w]`: **First Item Considered** - `Item 1`
      - `dp[2][w]`: **First Two Items Considered** - `Items 1 and 2`
      - `w`: represents the **Knapsack Capacity** - `Columns`

    - **Final Result**: `dp[2][2] = 3`, selecting **Item 2**

  - _Time Complexity_: `O(n * W)` - Each **Cell** of the **DP Matrix** is **Calculated Once**, where `n` is the **Number Of Items** and `W` is the **Maximum Capacity**
  - _Space Complexity_: `O(n * W)` - The **DP Matrix Stores** `(n + 1) * (W + 1) values`

---

- **Retrograde Analysis**
  - **Instead** of **Simulating The Game** from the **Initial State**, we consider the **Game States** and **Solve Them Backwards**, starting from the **Terminal States** whose **Outcomes** are **Already Known**
  - A **State** is **WIN** if **At Least One Valid Move** leads to a **LOSE State**.
  - A **State** is **LOSE** if **All Valid Moves** lead to **WIN States**
  - States whose **Outcomes Cannot Be Determined** may represent **DRAW States**, depending on the **Game Rules**

  ```mermaid
  flowchart TD
  A["Terminal States (Known Outcomes)"] --> B["Predecessor States"]
  B --> C["Determine WIN/LOSE Outcomes"]
  C --> D["Initial State"]
  ```

- _Time Complexity_: `O(V + E)` - Each **Game State** and **Transition** is processed at **Most Once**
- _Space Complexity_: `O(V + E)` - Stores the **Game States**, **Transitions** and their **Outcomes**

## Basic Function

- `assign(count, value)`
  - **Header**: `None`
  - **Replaces All Existing Elements** with `count` **Copies** of `value` and **Updates The Vector Size** to `count`
  - **Example**: `v.assign(5, 10) → {10, 10, 10, 10, 10}`
