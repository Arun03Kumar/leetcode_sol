class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Approach 1: Bruteforce

        // unordered_map<int, int> mp;
        // for(int &x: nums) mp[x]++;

        // priority_queue<P, vector<P>> pq;
        // for(auto [k, v]: mp) {
        //     pq.push({v, k});
        // }

        // vector<int> ans;
        // while(!pq.empty() && k--) {
        //     auto top = pq.top();
        //     pq.pop();
        //     ans.push_back(top.second);
        // }

        // return ans;


        // Approach 2: pq with restriction  O(nlogk)
        // means pq contains only elements upto k

        // unordered_map<int, int> mp;
        // for(int &x: nums) mp[x]++;

        // priority_queue<P, vector<P>, greater<P>> pq;

        // for(auto &[key, val]: mp) {
        //     pq.push({val, key});

        //     if(pq.size() > k) pq.pop();
        // }

        // vector<int> ans;
        // while(!pq.empty()) {
        //     auto top = pq.top();
        //     pq.pop();

        //     ans.push_back(top.second);
        // }

        // return ans;

        // Approach 3: Reverse Bucket sort
        // in bucket sort what we do we create a array of size where we store frequency of each index present in given array
        // but here we are trying to store the elements with given frequency as indexes
        // means we are assuming index as frequecy and we store elements which has frequency as those indexes

        unordered_map<int, int> mp;

        for(int &x: nums) {
            mp[x]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto &[key, val]: mp) {
            bucket[val].push_back(key);
        }

        int n = nums.size();
        vector<int> ans;
        for(int i = n; i >= 0; i--) {
            if(!bucket[i].empty() && k > 0) {
                for(int &y: bucket[i]) {
                    ans.push_back(y);
                    k--;
                }
            }
        }

        return ans;
    }
};