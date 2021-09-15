
                                                        LRU CACHING TECHNIQUE


The least recently used (LRU) page replacement algorithm, though similar in name to NRU, differs in the fact that LRU keeps track of page usage over a short period of 
time, while NRU just looks at the usage in the last clock interval. LRU works on the idea that pages that have been most heavily used in the past few instructions 
are most likely to be used heavily in the next few instructions too. While LRU can provide near-optimal performance in theory (almost as good as adaptive replacement cache), 
it is rather expensive to implement in practice. There are a few implementation methods for this algorithm that try to reduce the cost yet keep as much of the performance 
as possible.
The most expensive method is the linked list method, which uses a linked list containing all the pages in memory. At the back of this list is the least recently used 
page, and at the front is the most recently used page. The cost of this implementation lies in the fact that items in the list will have to be moved about every memory 
reference, which is a very time-consuming process.Another method that requires hardware support is as follows: suppose the hardware has a 64-bit counter that is incremented
at every instruction. Whenever a page is accessed, it acquires the value equal to the counter at the time of page access. Whenever a page needs to be replaced, 
the operating system selects the page with the lowest counter and swaps it out. Because of implementation costs, one may consider algorithms (like those that 
follow) that are similar to LRU, but which offer cheaper implementations. One important advantage of the LRU algorithm is that it is amenable to full statistical
analysis. It has been proven, for example, that LRU can never result in more than N-times more page faults than OPT algorithm, where N is proportional to the number 
of pages in the managed pool. On the other hand, LRU's weakness is that its performance tends to degenerate under many quite common reference patterns. 
    For example, if there are N pages in the LRU pool, an application executing a loop over array of N + 1 pages will cause a page fault on each and every access. 
  As loops over large arrays are common, much effort has been put into modifying LRU to work better in such situations. Many of the proposed LRU modifications 
 try to detect looping reference patterns and to switch into suitable replacement algorithm, like Most Recently Used (MRU).






Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) - Initialize the LRU cache with positive size capacity.
int get(int key) - Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) - Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.


Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output :- [null, null, null, 1, null, -1, null, -1, 3, 4]

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

SOLUTION :-
    

using key = int;

struct Entry 
{
    int value;
    list<key>::iterator itr;
};

class LRUCache 
{
    unordered_map<key, Entry> _cache;
    //old keys move to back, new ones enter at front
    list<key> _age;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) 
    {
        //if key is present, renew its age and return value
        if (_cache.count(key)) {
            _age.erase(_cache[key].itr);
            _age.push_front(key);
            _cache[key].itr = _age.begin();
            return _cache[key].value;
        }
        return -1;
    }

    void put(int key, int value) 
    {
        //if key is not present, check if the old entry need to be erased
        if (!_cache.count(key)) 
        {
            if (_cache.size() == _capacity) 
            {
                _cache.erase(_age.back());
                _age.pop_back();
            }
        }
        //key is present, just renew the age
        else 
        {
            _age.erase(_cache[key].itr);
        }
        _age.push_front(key);
        _cache[key] = { value, _age.begin() };
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
