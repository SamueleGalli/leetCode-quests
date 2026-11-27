# Tree Shaped Deep Forest

- **Binary Tree**
  - **Header**: `None`
  - A tree data structure made of **Nodes**
  - Each **Node** can have at most **2 Children**: **Left** and **Right**
  - The first node is called the **Root**
  - A node **Without Children** is called a **Leaf**

  **Example**:

  ```mermaid
  graph TD
      A[1] --> B[2]
      A --> C[3]
      B --> D[4]
      B --> E[5]
  ```

  - There are three common **Depth-First Traversal** methods:
    - **Pre Order**:
      - **ROOT → LEFT → RIGHT** - `1 → 2 → 4 → 5 → 3`
    - **In Order**:
      - **LEFT → ROOT → RIGHT** - `4 → 2 → 5 → 1 → 3`
    - **Post Order**:
      - **LEFT → RIGHT → ROOT** - `4 → 5 → 2 → 3 → 1`
  - _Time Complexity_:
    - _Traversal_: `O(n)`
    - _Search_: `O(n)`
    - _Space Complexity_: `O(h)` for **recursive traversal**
  - _Where_:
    - `n` = Number of **Nodes**
    - `h` = Height of the **Tree**

---

- A **Binary Tree** can have **Different Variants** and **Tree-Based Data Structures**:
  - **Binary Search Tree** - `BST`:
    - **Header**: `None`
    - A **Binary Tree** where:
      - All `values` in the **LEFT SUBTREE** are **Smaller** than the **ROOT**, and all `values` in the **RIGHT SUBTREE** are **Greater** than the **ROOT**
    - This **Ordering** allows efficient **Searching**, **Insertion** and **Deletion**

  **Example**:

  ```mermaid
  graph TD
      A[10] --> B[7]
      A --> C[12]
      B --> D[5]
      B --> E[9]
      C --> F[11]
      C --> G[15]
  ```

  - _Time Complexity_:
    - _Search / Insertion / Deletion_: `O(log n)` _average_, `O(n)` _worst case_
    - _Space Complexity_: `O(n)` for **Storing** the **Tree**

  - **Segment Tree**:
    - **Header**: `None`
    - A **Binary Tree** that represents **Ranges** of an `array`
    - The **Range** is **Recursively Divided** into **Smaller Ranges** to build the **Tree**
    - Each **Node Stores** information about its **Corresponding Range**
    - Allows **Efficient Range Queries** such as `sum, minimum, or maximum`
    - The **Information Stored** in each **Node** can be adapted to **Different Problems**
    - **Example Array**:
      - `A = [2, 1, 5, 3, 4, 7, 6, 8]`

    ```mermaid
    graph TD
        A["[0,7] = 36"] --> B["[0,3] = 11"]
        A --> C["[4,7] = 25"]
        B --> D["[0,1] = 3"]
        B --> E["[2,3] = 8"]
        D --> F[2]
        D --> G[1]
        E --> H[5]
        E --> I[3]
        C --> J["[4,5] = 11"]
        C --> K["[6,7] = 14"]
        J --> L[4]
        J --> M[7]
        K --> N[6]
        K --> O[8]
    ```

  - _Time Complexity_:
    - _Build_: `O(n)`
    - _Range Query_: `O(log n)`
    - _Point Update_: `O(log n)`
    - _Space Complexity_: `O(n)`

    - **Trie**:
      - **Header**: `None`
      - A **Tree Data Structure** used mainly to store `strings` and **Efficiently Search** for **Words** or **Prefixes**
      - Each **Edge** represents a `character`, and a path from the **Root** represents a **Prefix**
      - Each **Node** can have **Multiple Children**, depending on the **Alphabet Size**

    ```mermaid
    graph TD
    A[root] --> B[c]
    A --> C[d]
    B --> D[a]
    D --> E[t]
    D --> F[r]
    C --> H[o]
    H --> I[g]
    ```

    **Words**: `mean: cat, car, dog`
    - _Time Complexity_:
      - _Insert / Search / Prefix Search_: `O(L)`
      - _Space Complexity_: `O(S)` with **Sparse Child Storage**
    - **Where**:
      `L` = **Length** of the **Word**
      `S` = **Total Number** of **Characters Stored**

    - **Minimum Spanning Tree** - `MST`:
      - **Header**: `None`
      - A **Tree** that connects all `vertices` of a **Connected**, **Weighted**, **Undirected Graph** with the **Minimum Possible Total Edge Weight** and contains **No Cycles**.
      - Select **Edges** so that all **Vertices** are connected with the **Minimum Total Cost** without creating **Cycles**

      - **Example - Original Weighted Graph**:

      ```mermaid
      graph LR
      A ---|1| B
      A ---|3| C
      B ---|2| C
      ```

      - **Minimum Spanning Tree**:

      ```mermaid
      graph LR
      A ---|1| B
      B ---|2| C
      ```

    - **Selected Edges**:
      - `A -- B (1)`
      - `B -- C (2)`

    - **Total Weight** = `A(1) + B(2) = T(3)`
    - **Common Algorithms**:
      - **Prim**: Starts from **One Node** and repeatedly uses a **Priority Queue** to select the cheapest edge connecting the **Tree** to an **Unvisited Node**
      - **Kruskal**: **Sorts All Edges** by `weight` and uses a **DSU** - `Disjoint Set Union` to check whether **Adding** an **Edge** would create a **Cycle**, selecting the **Cheapest Valid Edges** until all `vertices` are **Connected**
    - _Time Complexity_:
      - _Prim (Adjacency List + Min-Heap)_: `O((V + E) log V)`
      - _Prim (Adjacency Matrix)_: `O(V²)`
      - _Kruskal_: `O(E log E)`
      - _Space Complexity_: `O(V + E)`
    - _Where_:
      - `V` = Number of **Vertices**
      - `E` = Number of **Edges**

---

- **Bitwise Operations**
  - **Header**: `None`
  - **Bitwise Operations** manipulate **Individual Bits** of an `integer` using **Binary Representations**.
  - **Bit Positions Start** from `0`, counting from the **Rightmost Bit** - `Least Significant Bit`

  - **Get Bit** - `(num >> bit) & 1`
    - Uses the **Right Shift Operator** - `>>` to move the **Desired Bit** to the **Rightmost Position**
    - Uses the **Bitwise AND Operator** - `&` with `1` to retrieve its value - `0 or 1`
    - Does **Not Modify** the **Original Number**

    - **Example**:

    ```cpp
    int num = 10; // 1010
    int bit = 1;  // 0001

    int Result = (num >> bit) & 1;
    /*
    1010 >> 1     0101
    0101 & 0001   0001

    Result = 1;
    */
    ```

    - _Time Complexity_: `O(1)`

  - **Set Bit** - `num |= (1 << bit)`
    - A **Bitmask** is a **Binary Value** used to **Select** or **Manipulate Specific Bits**
    - Uses the **Left Shift Operator** - `<<` to create a **Bitmask** with `1` at the **Desired Position**
    - Uses the **Bitwise OR Assignment Operator** - `|=` to set the **Selected Bit** to `1`
    - Leaves all **Other Bits Unchanged**
    - If the **Selected Bit** is already `1`, the value **Remains Unchanged**

    - **Example**:

    ```cpp
    int num = 8;   // 1000
    int bit = 1;   // 0001

    int Result = num |= (1 << bit);
    /*
    0001 << 1      0010
    1000 | 0010    1010

    Result = 10;
    */
    ```

    - _Time Complexity_: `O(1)`

  - **XOR** - `nume ^= bit`:
    - Performs a **Bitwise Exclusive OR Operation** between `two values`
    - Returns `1` when the corresponding **Bits Are Different**, and `0` when they are **Equal**
    - **Toggles The Bits** set to `1` in the **Second Operand**, leaving the **Other Bits Unchanged**

    - **XOR Truth Table**:

    | **FIRST BIT** | **SECOND BIT** | **RESULT** |
    | :-----------: | :------------: | :--------- |
    |      `0`      |      `0`       | `0`        |
    |      `0`      |      `1`       | `1`        |
    |      `1`      |      `0`       | `1`        |
    |      `1`      |      `1`       | `0`        |

    - **Example**:

    ```cpp
    int num = 10;    // 1010
    int bit = 6; // 0110

    int Result = name ^ bit;
    /*
    1010 ^ 0110 // 1100

    Result = 12;
    */
    ```

    - _Time Complexity_: `O(1)` per **Operation**

---

- **Optional** - `vector<optional<type>>`
  - **Header**: `<optional>`
  - A **Utility Type** that **Stores** either a `value` or an `empty state` - nullopt, allowing **Variables** to represent **Optional Values**

  - **Common Operations**:
    - `has_value()`: Checks whether a **Value** is **Present**
    - `value()`: **Returns** the **Stored Value**
    - `nullopt`: **Represents** an **Empty Optional**
  - _Time Complexity_: `O(1)` for **Basic Operations**
  - _Space Complexity_: `O(n)` for a `vector` containing `n` **Optional Elements**
