class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Approach 1: Compute all the prefix of arr1, then for each element in arr2 check if prefix of that is present in the set or not and store the ans.

        unordered_set<int> st;
        for(int x: arr1) {
            while(!st.count(x) && x > 0) { // check if num is already present in the set
                st.insert(x);
                x /= 10;
            }
        }

        int ans = 0;

        for(int x: arr2) {
            while(x > 0) {
                if(st.count(x)) break;
                x /= 10;
            }

            if(x > 0) { // we need to check this condition because log(0) is not defined
                ans = max(ans, static_cast<int>(log10(x) + 1));
            }   
        }

        return ans;
    }
};