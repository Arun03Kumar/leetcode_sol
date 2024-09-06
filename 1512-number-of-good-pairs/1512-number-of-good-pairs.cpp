class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // approach 1: brute-force
        // approach 2: store all in the map then find the combination of each frequecy and add into ans; this will take two passes of each element.
        // approach 3: we can ask questions to the current element that how much elements it has seen which are same, that much pair will it can make so simply add into ans and update the map

        unordered_map<int, int> freq;

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += freq[nums[i]];
            freq[nums[i]]++;
        }
        
        return ans;
    }
};