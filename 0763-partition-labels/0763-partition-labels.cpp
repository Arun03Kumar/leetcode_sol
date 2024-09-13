class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        // for(auto &[key, val]: mp) {
        //     cout << key << "->" << val <<endl;
        // }
        
        vector<int> ans;
        int size = 0, end = mp[s[0]];
        for(int i = 0; i < n; i++) {
            if(mp[s[i]] > end) end = mp[s[i]];
            size++;

            if(i == end) {
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};