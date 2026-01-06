class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> st;

        for(int x: arr) mp[x]++;

        for(auto &[key, val]: mp) {
            if(st.find(val) == st.end()) {
                st.insert(val);
            }
            else {
                return false;
            }
        }

        return true;
    }
};