class Solution {
public:
    void backtracking(unordered_map<int, int> &mp, vector<int> &curr, vector<vector<int>> &ans, int &n) {
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for(auto &[num, count]: mp) {
            if(count == 0) continue;

            curr.push_back(num);
            mp[num]--;
            backtracking(mp, curr, ans, n);

            curr.pop_back();
            mp[num]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // in permutation 1 we have to take care about the number itself
        // but here we have to take care of count of the number 
        // if count of the number is greater than 0 it means we can still take that number
        // and furthur do the same processing
        
        vector<vector<int>> ans;
        vector<int> curr;

        unordered_map<int, int> mp;
        int n = nums.size();

        for(int &x: nums) mp[x]++;

        backtracking(mp, curr, ans, n);
        return ans;
    }
};