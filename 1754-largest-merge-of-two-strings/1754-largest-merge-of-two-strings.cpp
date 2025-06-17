class Solution {
public:
    string largestMerge(string word1, string word2) {
        // compare() is more efficient than substr()
        // string ans = "";
        // int i = 0, j = 0;
        // while(i < word1.size() && j < word2.size()) {
        //     if(word1[i] > word2[j]) ans.push_back(word1[i++]);
        //     else if(word1[i] < word2[j]) ans.push_back(word2[j++]);
        //     else {
        //         if(word1.substr(i) >= word2.substr(j)) {
        //             ans.push_back(word1[i++]);
        //         }
        //         else ans.push_back(word2[j++]);
        //     }
        // }

        // while(i < word1.size()) ans.push_back(word1[i++]);
        // while(j < word2.size()) ans.push_back(word2[j++]);

        // return ans;

        // return ans + word1.substr(i) + word2.substr(j);


        // it returns 0 if both are equal, a positive if word1 is greater, else -ve number
        string ans;
        int i = 0, j = 0;
        int m = word1.size(), n = word2.size();

        while(i < m && j < n) {
            if(word1.compare(i, m - i, word2, j, n - j) > 0) {
                ans.push_back(word1[i++]);
            }
            else ans.push_back(word2[j++]);
        }

        return ans + word1.substr(i) + word2.substr(j);
    }
};

