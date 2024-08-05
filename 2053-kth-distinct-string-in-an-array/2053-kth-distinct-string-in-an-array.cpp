class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> ump;

        for(string s: arr) {
            ump[s]++;
        }

        int count = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(ump[arr[i]] > 1) continue;
            count++;
            if(count == k) return arr[i];
        }

        return "";
            
    }
};