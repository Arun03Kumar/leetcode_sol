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
            // int l = 0, r = x.size() - 1, flag = true;
            // while(l <= r) {
            //     if(x[l++] != x[r--]) {
            //         flag = false;
            //         break;
            //     }
            // }
            // if(flag) return x;
            for(int i=0; i<words.size(); i++){
            int p =0;
            int flag = true;
            string nword = words[i];
            int q = nword.length()-1;
            while(p<q){
                if(nword[p]!=nword[q]){
                    flag = false;
                }
                p++;
                q--;
            }
            if(flag == true){
                return words[i];
            }
        }
        return "";
        }
        return "";
    }
};