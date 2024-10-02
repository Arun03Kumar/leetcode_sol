class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int &x: nums) mp[x]++;

        priority_queue<P, vector<P>> pq;
        for(auto [k, v]: mp) {
            pq.push({v, k});
        }

        vector<int> ans;
        while(!pq.empty() && k--) {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }

        return ans;
    }
};