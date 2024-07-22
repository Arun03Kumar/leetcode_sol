class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> combine;
        for(int i = 0; i < names.size(); i++) {
            combine.push_back({names[i], heights[i]});
        }

        auto comparator = [&](auto x, auto y) {
            return x.second > y.second;        
        };
        sort(begin(combine), end(combine), comparator);

        vector<string> ans;
        for(auto x: combine) {
            ans.push_back(x.first);
        }

        return ans;
    }
};