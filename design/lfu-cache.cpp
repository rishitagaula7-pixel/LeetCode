#include <unordered_map>
#include <list>

using namespace std;

// Structure to store key, value, and its current frequency count
struct Node {
    int key;
    int value;
    int freq;
    Node(int k, int v, int f) : key(k), value(v), freq(f) {}
};

class LFUCache {
private:
    int cap;
    int min_freq;
    
    // Maps key -> Iterator pointing to the Node inside a list
    unordered_map<int, list<Node>::iterator> key_to_node;
    
    // Maps frequency -> Doubly Linked List of Nodes with that frequency
    unordered_map<int, list<Node>> freq_to_list;

    // Helper function to upgrade a node's frequency when accessed or updated
    void update_frequency(list<Node>::iterator it) {
        int key = it->key;
        int val = it->value;
        int old_freq = it->freq;
        
        // 1. Remove node from its current frequency list
        freq_to_list[old_freq].erase(it);
        
        // 2. If the current minimum frequency list becomes empty, update min_freq
        if (freq_to_list[old_freq].empty()) {
            freq_to_list.erase(old_freq);
            if (min_freq == old_freq) {
                min_freq++;
            }
        }
        
        // 3. Insert node into the incremented frequency list (at the front for LRU preservation)
        int new_freq = old_freq + 1;
        freq_to_list[new_freq].push_front(Node(key, val, new_freq));
        
        // 4. Update the node tracking reference
        key_to_node[key] = freq_to_list[new_freq].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        min_freq = 0;
    }
    
    int get(int key) {
        if (key_to_node.find(key) == key_to_node.end()) {
            return -1;
        }
        auto it = key_to_node[key];
        int val = it->value;
        update_frequency(it);
        return val;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        
        // Scenario A: Key already exists, update value and promote frequency
        if (key_to_node.find(key) != key_to_node.end()) {
            auto it = key_to_node[key];
            it->value = value;
            update_frequency(it);
            return;
        }
        
        // Scenario B: Cache is full, evict the LFU (and LRU if tied) node
        if (key_to_node.size() == cap) {
            // The back of the min_freq list is the least recently used among least frequently used
            auto& eviction_list = freq_to_list[min_freq];
            int key_to_evict = eviction_list.back().key;
            
            key_to_node.erase(key_to_evict);
            eviction_list.pop_back();
            
            if (eviction_list.empty()) {
                freq_to_list.erase(min_freq);
            }
        }
        
        // Scenario C: Insert new key-value pair
        min_freq = 1; // New elements always start with a frequency count of 1
        freq_to_list[1].push_front(Node(key, value, 1));
        key_to_node[key] = freq_to_list[1].begin();
    }
};
