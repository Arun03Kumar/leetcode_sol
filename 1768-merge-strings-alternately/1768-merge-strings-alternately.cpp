class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int first = 0, second = 0, cnt = 0;
        string ans = "";
        while(first < word1.size() && second < word2.size()) {
            if(cnt % 2 == 0) {
                ans += word1[first++];
            }
            else
                ans += word2[second++];
            cnt++;
        }
        while(first < word1.size())
            ans += word1[first++];
        
        while(second < word2.size())
            ans += word2[second++];

        return ans;
    }
};