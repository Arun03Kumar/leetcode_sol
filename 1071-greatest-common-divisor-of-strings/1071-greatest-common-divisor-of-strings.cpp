class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        string temp;
        if(m < n) temp = str1;
        else temp = str2;

        int size = temp.size();
        for(int i = size; i > 0; i--) {
            if(m % i == 0 && n % i == 0) {
                int q1 = m / i;
                int q2 = n / i;

                string s1 = "", s2 = "";
                for(int p = 0; p < q1; p++) s1 += temp;
                for(int p = 0; p < q2; p++) s2 += temp;

                if(s1 == str1 && s2 == str2) return temp;
            }

            temp.pop_back();
        }

        return "";
    }
};