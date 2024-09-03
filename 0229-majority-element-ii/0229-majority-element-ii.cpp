class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int candidate1 = NULL, count1 = 0;
        int candidate2 = NULL, count2 = 0;

        for(int i = 0; i < n; i++) {

            if(nums[i] == candidate1) {
                count1++;
            }
            else if(nums[i] == candidate2) {
                count2++;
            }
            else if(count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }

        }

        vector<int> ans;

        int freq1 = 0, freq2 = 0;

        for(int &x: nums) {
            if(x == candidate1) freq1++;
            if(x == candidate2) freq2++;
        }

        if(freq1 > floor(n / 3)) ans.push_back(candidate1);
        if(freq2 > floor(n / 3)) ans.push_back(candidate2);

        return ans;
    }
};