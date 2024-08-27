class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Approach 1: sorting O(k * nlogn) where k is the number of strings and let n is the size of the longest string
        // just sort each word and add that into the map of it

    //     unordered_map<string, vector<string>> mp;

    //     for(int i = 0; i < strs.size(); i++) {
    //         string temp = strs[i];
    //         sort(begin(temp), end(temp));
    //         mp[temp].push_back(strs[i]);
    //     }

    //     vector<vector<string>> ans;

    //     for(auto x: mp) {
    //         ans.push_back(x.second);
    //     }

    //     return ans;
    // }


    // Approach 2: it is simillar to the above but we will now store the strings in the array based on indexes because it is given that the all string are lower case letters.

    unordered_map<string, vector<string>> mp;

    for(int i = 0; i < strs.size(); i++) {
        vector<int> temp(26, 0);
        for(char x: strs[i]) {
            temp[x - 'a']++;
        }

        string temp_str = "";

        for(int k = 0; k < 26; k++) {
            if(temp[k] == 0) continue;

            int freq = temp[k];
            string new_str = string(freq, k + 'a');
            temp_str += new_str;
        }

        mp[temp_str].push_back(strs[i]);
    }

    vector<vector<string>> ans;

    for(auto x: mp) {
        ans.push_back(x.second);
    }

    return ans;
    }

};