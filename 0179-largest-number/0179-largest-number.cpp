class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comp = [](int &x, int &y) {

            string s1 = to_string(x);
            string s2 = to_string(y);

            return s1 + s2 > s2 + s1; // strign concatanation
        };

        sort(begin(nums), end(nums), comp);

        if(nums[0] == 0) return "0"; // because if first element is zero then other elements will also be 0

        string ans = "";

        for(int &x: nums) ans += to_string(x);

        return ans;
    }   
};