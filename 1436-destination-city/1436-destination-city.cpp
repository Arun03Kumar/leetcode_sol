class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> freq;
        for(auto &x: paths) {
            freq[x[0]]++;
            freq[x[1]]++;
        }

        for(auto &x: freq) {
            if(x.second == 1) {
                for(auto &y: paths) {
                    if(y[1] == x.first) return x.first;
                }
            }
        }

        return "";
    }
};