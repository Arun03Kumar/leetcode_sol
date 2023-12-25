class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, element1 = INT_MIN, element2 = INT_MIN;
        for(auto x: nums) {
            if(count1 == 0 && x != element2) {
                element1 = x;
                count1 = 1;
            }
            else if(count2 == 0 && x != element1) {
                element2 = x;
                count2 = 1;
            }
            else if(x == element1) count1++;
            else if(x == element2) count2++;
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(auto x: nums) {
            if(x == element1) count1++;
            if(x == element2) count2++;
        }
        vector<int> ans;
        if(count1 > (nums.size() / 3)) ans.push_back(element1);
        if(count2 > (nums.size() / 3)) ans.push_back(element2);
        return ans;
    }
};