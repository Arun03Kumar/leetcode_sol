class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char ch: s) {
            freq[ch]++;
        }

        vector<pair<int, char>> arr;
        for(auto [key, val]: freq) {
            arr.push_back(make_pair(val, key));
        }

        sort(begin(arr), end(arr), greater<pair<int, char>>());
        
        string ans = "";
        for(auto x: arr) {
            ans.append(x.first, x.second);
        }
        return ans;
    }
};