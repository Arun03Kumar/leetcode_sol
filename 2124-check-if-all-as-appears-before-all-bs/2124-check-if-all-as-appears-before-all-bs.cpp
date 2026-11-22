class Solution {
public:
    bool checkString(string s) {
        int is_a = 1;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'b') is_a = 0;

            if(s[i] == 'a' && is_a == 0) return false; 
        }

        return true;
    }
};