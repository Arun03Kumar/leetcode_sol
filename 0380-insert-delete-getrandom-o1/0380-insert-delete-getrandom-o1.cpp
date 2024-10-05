class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;

        arr.push_back(val);
        mp[val] = arr.size() - 1;

        return true;  
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;

        int idx_of_val = mp[val];
        int last_el = arr.back();
        arr.back() = val;

        arr[idx_of_val] = last_el;
        mp[last_el] = idx_of_val;

        arr.pop_back();
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        int rand_idx = rand() % arr.size(); // this gives a value from 0 to arr.size() - 1
        return arr[rand_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */