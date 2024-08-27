class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Approach 1: sorting
        // just sort each word and add that into the map of it
        
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(begin(temp), end(temp));
            mp[temp].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto x: mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};