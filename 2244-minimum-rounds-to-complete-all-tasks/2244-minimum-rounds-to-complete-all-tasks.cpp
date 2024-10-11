class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(int &x: tasks) mp[x]++;

        int ans = 0;
        for(auto [key, val]: mp) {
            if(val == 1) return -1;

            ans += ceil((double)val / 3);
        }

        return ans;
    }
};