// https://www.interviewbit.com/problems/lru-cache/

#include<list>
#define listIter list<int>::iterator

int capacity;
// Doubly linked list to store a queue of keys
// Most recently used will be at the front
// Least recently used will be at the back, and will be popped out
list<int> dll;
unordered_map<int, int> keyToValueMap;
// Key to dll iterator map
unordered_map<int, listIter> keyToIterMap;

// Utility methods
void addKeyToFront(int key) {
    dll.push_front(key);
    keyToIterMap[key] = dll.begin();
}

void moveKeyToFront(int key) {
    dll.erase(keyToIterMap[key]);
    addKeyToFront(key);
}

void popBack() {
    int backKey = dll.back();
    dll.pop_back();
    keyToValueMap.erase(backKey);
    keyToIterMap.erase(backKey);
}

// LRUCache methods
LRUCache::LRUCache(int _capacity) {
    capacity = _capacity;
    dll.clear();
    keyToValueMap.clear();
    keyToIterMap.clear();
}

int LRUCache::get(int key) {
    // If key is absent
    if (keyToValueMap.find(key) == keyToValueMap.end()) return -1;
    moveKeyToFront(key);
    return keyToValueMap[key];
}

void LRUCache::set(int key, int value) {
    // If key is already present
    if (keyToValueMap.find(key) != keyToValueMap.end()) moveKeyToFront(key);
    else {
        // Key is new so if capacity is reached, pop one element from back
        if (keyToValueMap.size() == capacity) popBack();
        // Add new key to front
        addKeyToFront(key);
    }
    // Update value in map
    keyToValueMap[key] = value;
}
