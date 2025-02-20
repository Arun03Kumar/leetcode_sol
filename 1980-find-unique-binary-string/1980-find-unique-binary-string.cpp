class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // int n = nums.size();

        // unordered_set<int> st;
        // for(string num: nums) {
        //     st.insert(stoi(num, 0, 2));
        // }

        // string ans = "";
        // for(int i = 0; i <= n; i++) {
        //     if(st.find(i) == st.end()) {
        //         ans = bitset<16>(i).to_string();
        //         break;
        //     }
        // }

        // return ans.substr(16 - n, n);


        // Approach 2: since ans and size of each string will be same, so we go to each string and we try to iterate on the indexes also, and in the ans index assign a different value than present in the number this way we eliminate the possibility that number won't be repeated

        string ans = "";
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            char ch = nums[i][i];
            if(ch == '0') ans.push_back('1');
            else ans.push_back('0');
        }

        return ans;
    }
};