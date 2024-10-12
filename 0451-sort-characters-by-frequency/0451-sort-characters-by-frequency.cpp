class Solution {
public:
    typedef pair<int, char> P;
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char ch: s) mp[ch]++;

        priority_queue<P, vector<P>> pq;
        for(auto [key, val] : mp) {
            pq.push({val, key});
        } 

        string ans;

        while(!pq.empty()) {
            char ch = pq.top().second;
            int freq = pq.top().first;

            string temp(freq, ch);
            ans += temp;
            pq.pop();
        }

        return ans;
    }
};