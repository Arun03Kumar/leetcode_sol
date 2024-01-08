class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for(string x: words) {
            string temp = "";
            int l = x.size();
            while(--l >= 0) temp += x[l];
            // cout << temp << " ";
            if(temp == x) {
                ans = x;
                break;
            }
        }
        return ans;
    }
};