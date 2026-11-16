# Tree Shaped Deep Forest

- **Binary Tree**
  - A tree data structure made of **nodes**
    - Each node can have at most 2 children `left and right`
    - The first node is called the **root**
    - A node without children is called a **leaf**

    ```mermaid
    graph TD
        A[1] --> B[2]
        A --> C[3]
        B --> D[4]
        B --> E[5]
    ```

    - There are three ways of traversing them:
      - Pre Order:
        - **ROOT → LEFT → RIGHT** - `1 → 2 → 4 → 5 → 3`
      - In Order:
        - **LEFT → ROOT → RIGHT** -  `4 → 2 → 5 → 1 → 3`
      - Post Order:
        - **LEFT → RIGHT → ROOT** - `4 → 5 → 2 → 3 → 1`

    ---

  - A **Binary Tree** can have different specializations:
    - **Binary Search Tree** - `BST`:
      - A **binary tree** where:
        - `LEFT < ROOT < RIGHT`
        - This allows efficient searching, insertion and deletion

    - **Segment Tree**:
      - A **Binary Tree** that represents ranges of an array
      - The range is recursively divided into smaller ranges to build the tree
      - Allowing efficient range queries such as `sums, minimums, or maximums`
      - The information stored in each node can be adapted to the problem allowing it to be used for more complex tasks such as interval scheduling
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
        K --> N[8]
    ```

    ---

    - **Trie**:
      - A tree used mainly to store strings and efficiently search for **words** or **prefixes**
      - Each **edge** represents a character, and a path from the **root** represents a word
      - A node can have more than two children

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

    `mean: cat, car, dog`

    ---

    - **Minimum Spanning Tree** - `MST`:
      - A tree that connects all vertices with the minimum possible total edge weight and contains no cycles
      - Select **edges** so that all **vertices** are connected with the minimum total cost without creating **cycles**

    ```mermaid
    graph RL
    A ---|1| B
    A ---|3| C
    B ---|2| C
    ```

    - `A -- B (1)` - `B -- C (2)`
    - Total weight = `A(1) + B(2) = T(3)`
    - There are two common ways:
      - **Prim**: Starts from one node and repeatedly uses a **Priority Queue** to select the cheapest edge connecting the **Tree** to an **Unvisited Node**
      - **Kruskal**: Sorts all edges by weight and uses a **DSU** - `Disjoint Set Union` to check whether adding an **edge** would create a **cycle**, selecting the cheapest valid edges until all vertices are connected
