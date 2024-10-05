class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //  Approach 1: TLE
        // just sort the string p and find the substring of lenth p then sort it and comapre the both strings
        // int n = p.size();
        // vector<int> ans;

        // if(n > s.size()) return {};

        // sort(begin(p), end(p));

        // for(int i = 0; i <= s.size() - n; i++) {

        //     string substring = s.substr(i, n);
        //     sort(begin(substring), end(substring));

        //     if(substring == p) {
        //         ans.push_back(i);
        //     }

        // }

        // return ans;


        // Approach 2: sliding window

        int n = p.size(), m = s.size();

        if(n > m) return {};

        vector<int> ans;

        vector<int> freq_p(26, 0);
        
        for(char ch: p) freq_p[ch - 'a']++;

        vector<int> freq_s(26, 0);
        for(int i = 0; i < n; i++) freq_s[s[i] - 'a']++;

        int l = 0, r = n;

        while(r < m) {
            if(freq_s == freq_p) {
                ans.push_back(l);
            }

            freq_s[s[r] - 'a']++;
            freq_s[s[l] - 'a']--;

            l++;
            r++;
        }

        if(freq_s == freq_p) ans.push_back(l);

        return ans;
    }
};