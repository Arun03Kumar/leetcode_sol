class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        // string ans = "";
        for(string x: words) {
            // string temp = "";
            // int l = x.size();
            // while(--l >= 0) temp += x[l];
            // // cout << temp << " ";
            // if(temp == x) {
            //     ans = x;
            //     break;
            // }
            int l = 0, r = x.size() - 1, flag = true;
            while(l <= r) {
                if(x[l++] != x[r--]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return x;
        }
        return "";
    }
};