class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Approach 2: 
        // start from the end of both strings and increse the count of #
        // if we get any character but count of # is still greater than 0 then skip the character
        // else break that loop
        // do this for 2nd string 
        // now in the end compare the characters
        // if equal then do this for rest characters

        int i = s.size() - 1;
        int j = t.size() - 1;

        int count_s = 0, countt = 0;

        while(i >= 0 || j >= 0) {

            while(i >= 0) {
                if(s[i] == '#') {
                    count_s++;
                    i--;
                }
                else if(count_s > 0) {
                    count_s--;
                    i--;
                }
                else break;

            }

            while(j >= 0) {
                if(t[j] == '#') {
                    countt++;
                    j--;
                }
                else if(countt > 0) {
                    countt--;
                    j--;
                }
                else break;
            }

            char first = i < 0 ? '$' : s[i]; 
            char sec = j < 0 ? '$' : t[j]; 

            if(first != sec) return false;

            i--;
            j--;
        }

        return true;
    }
};