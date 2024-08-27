class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        vector<int> v;
        for(int i = 0; i < nums.size(); i++) {
            v.push_back(i);
            if(m[target - nums[i]] && m[target - nums[i]] != i){
                v.push_back(m[target - nums[i]]);
                return v;
            }
            v.clear();
        }
        return v;
    }
};