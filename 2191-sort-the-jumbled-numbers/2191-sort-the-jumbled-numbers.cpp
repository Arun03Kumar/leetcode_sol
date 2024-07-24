class Solution {
public:
    int mapped(int num, vector<int> &mapping) {
        if(num < 10) {
            return mapping[num];
        }

        int new_num = 0;
        int mult = 1;
        int temp = num;
        while(temp) {
            int rem = temp % 10;
            new_num += (mapping[rem] * mult);
            mult *= 10;
            temp /= 10;

        }

        // cout << new_num << endl;

        return new_num;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        vector<pair<int, int>> vec;
        for(int i = 0; i < nums.size(); i++) {
            int mapped_num = mapped(nums[i], mapping);
            vec.push_back({mapped_num, i});
        }

        sort(begin(vec), end(vec));

        vector<int> ans;

        for(auto x: vec) {
            ans.push_back(nums[x.second]);
        }

        return ans;
        
        // auto comp = [&](int num1, int num2) {
        //     int mapped_num1 = mapped(num1, mapping);
        //     int mapped_num2 = mapped(num2, mapping);

        //     if(mapped_num1 == mapped_num2) return num1 >= num2;

        //     return mapped_num2 > mapped_num1;
        // };
        // sort(begin(nums), end(nums), comp);

        // return nums;
    }
};