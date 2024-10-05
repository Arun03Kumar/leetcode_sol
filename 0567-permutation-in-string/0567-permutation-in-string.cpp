class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Approach 1: O((n - m) * nlogn)  Space Comp: O(n) // because creating substring
        // Create a sliding window of size s1.size
        // then iterate over s2 and for each index create a substring starting from idx upto length s1.size
        // then compare the created substring with the s1
        // we can compare by sorting or by creating frequency array

        // int m = s1.size(), n = s2.size();

        // sort(s1.begin(), s1.end());

        // for(int i = 0; i <= n - m; i++) {
            
        //     string substring = s2.substr(i, m);
        //     sort(substring.begin(), substring.end());

        //     if(s1 == substring) return true;
        // }

        // return false;


        //  Approach 2: sliding window
        // in this we create a window of size s1 and create frequency array of it
        // then for each sliding window we compare the frequecy with original if they match then 

        int m = s1.size(), n = s2.size();

        vector<int> s1_freq(26, 0);
        for(char ch: s1) s1_freq[ch - 'a']++;

        vector<int> s2_window_freq(26, 0);
        for(int i = 0; i < m; i++) {
            s2_window_freq[s2[i] - 'a']++;
        } 

        int l = 0, r = m; // r is one index after the sliding window

        while(r < n) {
            if(s2_window_freq == s1_freq) return true;

            s2_window_freq[s2[r] - 'a']++;
            s2_window_freq[s2[l] - 'a']--;

            l++;
            r++;
        }

        return s2_window_freq == s1_freq;

    }
};