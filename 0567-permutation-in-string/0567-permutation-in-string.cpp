class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Approach 1: O((n - m) * nlogn)  Space Comp: O(n) // because creating substring
        // Create a sliding window of size s1.size
        // then iterate over s2 and for each index create a substring starting from idx upto length s1.size
        // then compare the created substring with the s1
        // we can compare by sorting or by creating frequency array

        int m = s1.size(), n = s2.size();

        sort(s1.begin(), s1.end());

        for(int i = 0; i <= n - m; i++) {
            
            string substring = s2.substr(i, m);
            sort(substring.begin(), substring.end());

            if(s1 == substring) return true;
        }

        return false;
    }
};