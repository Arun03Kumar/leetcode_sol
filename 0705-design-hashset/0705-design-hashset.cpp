class MyHashSet {
public:
    int M;
    vector<list<int>> buckets;

    int get_index(int key) {
        return key % M;
    }

    MyHashSet() {
        M = 15000;
        buckets = vector<list<int>>(M, list<int>{});
    }
    
    void add(int key) {
        int idx = get_index(key);

        auto it = find(buckets[idx].begin(), buckets[idx].end(), key);

        if(it == buckets[idx].end()) buckets[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = get_index(key);
        auto it = find(buckets[idx].begin(), buckets[idx].end(), key);
        if(it != buckets[idx].end()) buckets[idx].erase(it);
    }
    
    bool contains(int key) {
        int idx = get_index(key);
        auto it = find(buckets[idx].begin(), buckets[idx].end(), key);
        return it != buckets[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */