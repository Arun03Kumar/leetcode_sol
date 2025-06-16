class Solution {
public:
    string reverseVowels(string s) {
        string vow = "aeiouAEIOU";
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j) {
            while(i < n && vow.find(s[i]) == string::npos) i++;
            while(j >= 0 && vow.find(s[j]) == string::npos) j--;
            if(i < j) swap(s[i++], s[j--]); // mandatory check else it may possible that i and j cross each other and you still do swaps
        }
        return s;
    }
};