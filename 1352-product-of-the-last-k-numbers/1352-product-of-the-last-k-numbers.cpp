class ProductOfNumbers {
public:
    vector<int> prefix;
    // vector<int> count;
    int last_idx, count;
    ProductOfNumbers() {
        prefix.push_back(1);
        // count.push_back(0);
        count = 0;
        last_idx = -1;
    }

    // 2 3 5 4
    // 2 6 30 120
    
    void add(int num) {
        // nums.push_back(num);
        if(num == 0) {
            // count.push_back(count.back() + 1);
            last_idx = count;
            prefix.push_back(num);
        } 
        else if(prefix.back() == 0) {
            prefix.push_back(num);
            // count.push_back(count.back());
        }
        else {
            prefix.push_back(num * prefix.back());
            // count.push_back(count.back());
        }
        count++;
    }
    
    int getProduct(int k) {
        // for(int x: prefix) cout << x << " ";
        // cout << endl;
        // for(int x: count) cout << x << " ";
        // cout << endl;
        int idx = prefix.size() - k - 1;
        if(idx <= last_idx) return 0;
        // if(count.back() - count[idx] > 0) return 0;
        
        if(prefix[idx] == 0) return prefix.back();
        return prefix.back() / prefix[idx];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */