/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    * int get(int key) Return the value of the key if the key exists, otherwise return -1.
    * void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
    * The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
    ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output
    [null, null, null, 1, null, -1, null, -1, 3, 4]

    Explanation
        LRUCache lRUCache = new LRUCache(2);
        lRUCache.put(1, 1); // cache is {1=1}
        lRUCache.put(2, 2); // cache is {1=1, 2=2}
        lRUCache.get(1);    // return 1
        lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        lRUCache.get(2);    // returns -1 (not found)
        lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        lRUCache.get(1);    // return -1 (not found)
        lRUCache.get(3);    // return 3
        lRUCache.get(4);    // return 4


Constraints:

* 1 <= capacity <= 3000
* 0 <= key <= 10^4
* 0 <= value <= 10^5
* At most 2 * 10^5 calls will be made to get and put.
*/

using namespace std;

#include <iostream>
#include <unordered_map>

class List
{
protected:
    int key;
    int value;
    List *prev;
    List *next;

    List(int key, int value, List *prev = nullptr) : key(key), value(value), prev(prev), next(nullptr)
    {
    }
    friend class LRUCache;
};

class LRUCache
{
    unordered_map<int, List *> LRU;
    List *head = nullptr;
    List *tail = nullptr;
    int dim_LRU = 0;

private:
    void exist_node(List *node, List *prev_node = nullptr, List *next_node = nullptr)
    {
        if (node != tail)
        {
            if (node == head)
            {
                head = head->next;
                head->prev = nullptr;
            }
            else
            {
                prev_node = node->prev;
                next_node = node->next;

                prev_node->next = next_node;
                next_node->prev = prev_node;
            }

            tail->next = node;
            node->prev = tail;
            tail = tail->next;
            tail->next = nullptr;
        }
    }

    void update_put(int key, int value, List *node)
    {
        if (!node)
        {
            if (tail == head)
            {
                delete (head);
                head = new List(key, value);
                tail = head;
            }
            else
            {
                head = head->next;
                delete (head->prev);
                head->prev = nullptr;
                tail->next = new List(key, value, tail);
                tail = tail->next;
            }
        }
        else
            exist_node(node);
    }

public:
    LRUCache(int capacity)
    {
        dim_LRU = capacity;
    }

    int get(int key)
    {
        if (LRU.count(key))
        {
            if (LRU[key] == tail)
                return (LRU[key]->value);
            
            exist_node(LRU[key]);
            return (LRU[key]->value);
        }
        else
            return (-1);
    }

    void put(int key, int value)
    {
        if (dim_LRU > 0 && !LRU.count(key))
        {
            if (!head)
            {
                head = new List(key, value);
                tail = head;
            }
            else
            {
                tail->next = new List(key, value, tail);
                tail = tail->next;
            }
            dim_LRU--;
        }
        else
        {
            List *node = nullptr;
            if (LRU.count(key))
            {
                node = LRU[key];
                node->value = value;
            }
            else
                LRU.erase(head->key);
            update_put(key, value, node);
        }
        LRU[key] = tail;
    }

    ~LRUCache()
    {
        LRU.clear();
        while (head && head->next)
        {
            head = head->next;
            delete (head->prev);
        }
        delete (head);
    }
};

/*
    Your LRUCache object will be instantiated and called as such:
    LRUCache* obj = new LRUCache(capacity);
    int param_1 = obj->get(key);
    obj->put(key,value);
 */

int main()
{
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1); // cache is {1=1}
    obj->put(2, 2); // cache is {1=1, 2=2}
    int param = obj->get(1);
    cout << "param = " << param << endl; // return 1
    obj->put(3, 3);                      // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    param = obj->get(2);
    cout << "param = " << param << endl; // returns -1 (not found)
    obj->put(4, 4);                      // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    param = obj->get(1);
    cout << "param = " << param << endl; // returns -1 (not found)
    param = obj->get(3);
    cout << "param = " << param << endl; // return 3
    param = obj->get(4);
    cout << "param = " << param << endl; // return 4
    delete (obj);
}