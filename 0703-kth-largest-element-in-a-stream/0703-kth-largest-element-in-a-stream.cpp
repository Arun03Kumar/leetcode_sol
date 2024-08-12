class KthLargest {
public:
    // here we are removing all the min elements in the priority queue ensuring top element is always the kth largest element.
    // so at each push in pq we check if its size is greater than k then we pop from the pq.
    // if in the start there are n elements then adding them and maintaing the pq will cost nlogk time because we are maintaing at most k because at each insert pq will rearrange itself and that takes logk time.
    // then then are m add operation then it will cost mlogk.
    // so total (n + m)logk.
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int x: nums) {
            pq.push(x);

            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > K) {
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */