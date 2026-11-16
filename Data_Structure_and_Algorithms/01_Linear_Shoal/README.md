# Linear Shoal

- **Array**
  - A data structure with contiguous memory allocation
  - `O(1)` random access to elements via indices

    ```mermaid
    block-beta
        columns 6
        A["10"] B["50"] C["30"] D["60"] E["20"] F["40"]
    ```

---

- **Stack**
  - A **LIFO** `Last-In, First-Out` data structure
  - The last element added is the first one to be removed

---

- **Monotonic Stack**
  - A **Stack** maintained in a specific order:

    - **Increasing Stack**: Elements are maintained in increasing order

     ```mermaid
    block-beta
        columns 6
        A["10"] B["20"] C["30"] D["40"] E["50"] F["60"]
    ```

    - **Decreasing Stack**: Elements are maintained in decreasing order

    ```mermaid
    block-beta
        columns 6
        A["60"] B["50"] C["40"] D["30"] E["20"] F["10"]
    ```

  - Work in `0(n)` time complexity
