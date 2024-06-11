class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> count;
        vector<int> rem, res;

        for(int i = 0; i < arr2.size(); i++) {
            count[arr2[i]] = 0;
        }

        for(int i = 0; i < arr1.size(); i++) {
            if(count.find(arr1[i]) != count.end()) {
                count[arr1[i]]++;
            }
            else {
                rem.push_back(arr1[i]);
            }
        }

        for(int i = 0; i < arr2.size(); i++) {
            while(count[arr2[i]]--) {
                res.push_back(arr2[i]);
            }
        }

        sort(rem.begin(), rem.end());
        for(int x: rem) {
            res.push_back(x);
        }
        return res;
    }
};