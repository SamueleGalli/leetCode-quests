# Graph Theory Peaks

- **Graph**
  - **Header**: `None`
  - A **Data Structure** consisting of nodes - `vertices` and connections between them - `edges` - **Connections Between Vertices**
  - Used to represent **Relationships Between Elements**

  - **Representation**:
    - `G = (V, E)` for an **Unweighted Graph**
    - `G = (V, E, w)` for a **Weighted Graph**

  - **Where**:
    - `V`: represents the set of `vertices`
    - `E`: represents the set of `edges`
    - `w`: **Weight Function** that assigns a `weight` to each `edge`

  - _Time Complexity_: Depends on the **Graph Representation** and operation
  - _Space Complexity_:
    - _Adjacency List_: `O(V + E)`
    - _Adjacency Matrix_: `O(V²)`
    - _Edge List_: `O(E)`

  **Examples**:

  ```cpp
  // Weighted Edge List
  vector<vector<int>> weighted_edges = {{0, 1, 10},{1, 2, 11},{2, 3, 12},{1, 3, 13}};

  // Unweighted Edge List
  vector<vector<int>> unweighted_edges = {{0, 1},{1, 2},{2, 3},{1, 3}};
  ```

---

- **Union Find** - `Disjoint Set Union` - `DSU`
  - **Header**: `None`
  - A **Data Structure** used to manage a **Collection** of `disjoint sets`, keeping track of **Which Elements** belong to the **Same Group** using an `indexed array` to keep track of the **Parent** of each element
  - Each element starts as an `independent set`, therefore a size array is `often initialized` with `1`

  - **Initialization**:
    - Each element starts in an `independent set`
    - `parent[i] = i`: initializes each element as its own **Parent**
    - `size[i] = 1`: initializes the `size` of each `independent set` when using **Union By Size**

  - **Operations**:
    - **Find**: Returns the **Representative** - `root` of the `set` containing an element
    - **Union**: Merges two different sets into a single set

  - **Optimizations**:
    - **Path Compression**: Reduces **Tree Depth** during **Find** by connecting **Visited Elements** directly to the `root`
      **Before**:

    ```mermaid
      flowchart BT
      A["1(Root)"]
      B["2"] --> A
      C["3"] --> B
      D["4"] --> C
    ```

    **After**:

    ```mermaid
      flowchart BT
      A["1(Root)"]
      B["2"] --> A
      C["3"] --> A
      D["4"] --> A
    ```

    - **Union by Size/Rank**: Keeps `trees` balanced by **Attaching** the `smaller or lower-ranked tree` to the `larger or higher-ranked tree`
      **Before**:

    ```mermaid
      flowchart BT
      A["1 (Root, Size=3)"]
      B["2"] --> A
      C["3"] --> A
      D["4(Root,Size=2)"]
      E["5"] --> D
    ```

    **After**:

    ```mermaid
      flowchart BT
      A["1(Root, Size=5)"]
      B["2"] --> A
      C["3"] --> A
      D["4"] --> A
      E["5"] --> D
    ```

  - **Additional Feature**:
    - When **Elements** cannot be directly used as `array indexes e.g. large values, arbitrary values, or objects`, a `map` or `unordered_map` can be used to **Convert** them into `numeric indexes`
    - A `size array` can **Track** the number of elements in each connected component that are updated at the `root` whenever two sets are **Merged**
    - The **Largest Component** can be retrieved by maintaining a `max_size variable` or scanning the `root elements`

  - _Time Complexity_:
    _Initialization_: `O(n)`
    _Find_: `O(α(n)) amortized`
    _Union_: `O(α(n)) amortized`
    _Space Complexity_: `O(n)`
    **Where**:
    `n` = Number of **Elements**
    `α(n)` = Inverse **Ackermann Function**

---

- **DFS** - `Depth First Search`
  - A **Graph Traversal Algorithm** that explores **As Far As Possible** along one `branch` before **Backtracking** to explore `remaining branches`
  - Can be implemented **Recursively** or **Iteratively** using a `stack`
  - _Time Complexity_:
    - _Adjacency List_: `O(V + E)`
    - _Adjacency Matrix_: `O(V²)`
    - _Space Complexity_: `O(V)` for the `visited array` and `recursion stack` or `explicit stack`

---

- **BFS** - `Breadth-First Search`
  - A **Graph Traversal Algorithm** that explores `nodes` **Level By Level**
  - It starts from a `source node` and uses a `queue` - **FIFO** to keep track of **Nodes To Visit**
  - It visits all **Unvisited Neighbors** before moving to the **Next Level**
  - _Time Complexity_:
    - _Adjacency List_: `O(V + E)`
    - _Adjacency Matrix_: `O(V²)`
    - _Space Complexity_: `O(V)` for the visited `array and queue`

---

- **Dijkstra** - `Dijkstra's Shortest Path Algorithm`
  - Finds the **Shortest Path** from a `starting node` - `Source` to all other `reachable nodes` in a **Weighted Graph** with `non-negative edge weights`
  - It always processes the `node` with the **Smallest Known Distance** and `updates` the distances of its `neighbors` whenever a **Shorter Path** is found - `Relaxation`

  - **Common Data Structures**:
    - **Graph**: `vector` storing vertices, neighbors and `edge weights`
    - **Min-Heap**: `priority_queue` selecting the `node` with the **Smallest Distance**.
    - **Distances**: `vector` storing the **Shortest Known Distance** to each `vertex`

  - _Time Complexity_:
    - _Adjacency List + Min-Heap_: `O((V + E) log V)`
    - _Adjacency Matrix_: `O(V²)`
    - _Space Complexity_: `O(V + E)` including the **Graph Representation**
  - **Note**: **Dijkstra** does not support `negative edge weights`

  **Example**:

  ```mermaid
    flowchart LR
    A["A:0"]
    B["B:3"]
    C["C:1"]
    D["D:4"]
    A --4--> B
    A --1--> C
    B --1--> D
    C --2--> B
    C --5--> D
  ```

---

- **Enum**
  - **Header**: `None`
  - A **User-Defined Type** that defines a set of **Named Constants**, allowing related `values` to be **Grouped** under a **Common Type**

  **Declaration Example**:

```cpp
  enum class Status {
    Pending,
    InProgress,
    Completed
  };

  Status current_status = Status::Pending;
```

## Basic Function

|           **FUNCTION**            | **LIBRARY** | **DEFINITION**                                                          |
| :-------------------------------: | :---------: | :---------------------------------------------------------------------- |
|  `fill(v.begin(),v.end(),value)`  |   `None`    | Assigns the **Given Value** to every element in the **Specified Range** |
| `numeric_limits<type>::max/min()` | `<limits>`  | Returns the `maximum/minimum value` representable by the **Type**       |
|            `v.clear()`            |   `None`    | **Removes** all elements from the `container`                           |
