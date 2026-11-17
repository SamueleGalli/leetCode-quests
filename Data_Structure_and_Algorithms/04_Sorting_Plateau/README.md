# Sorting Plateau

- **Binary Search**
  - An efficient search algorithm for pre-sorted arrays
  - The recursive divise make the algorithm `O(log n)` time complexity

---

- **Counting Sort** - **Merge Sort** - **Quickselect**

  - **Counting Sort** - `sort`:
    - Create an array of size equal to the maximum value
    - Count and mark every occurrence of the values
    - Reconstruct the array using these counts

  - **Merge Sort** - `sort`:
    - Recursively divide the array into halves until single elements are reached
    - Merge all portions in order

  - **Quickselect** - `find`:
    - Select a pivot
    - Partition the array so that smaller elements are on the left and larger elements are on the right
    - Discard the "useless" portion and continue until the target element is found

---

- **Divide and Conquer**
  - It divides the problem like Merge Sort does, resolves the base case, and then works with the small elements obtained to build the final solution
