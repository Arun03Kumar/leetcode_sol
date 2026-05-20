class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, i = 0;
        int n = s.size();
        while(i < n && s[i] == ' ') i++;
        if(i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(s[i] == '+') i++;

        long long ans = 0;
        while(i < n && isdigit(s[i])) {
            int x = s[i] - '0';
            ans = ans * 10 + x;
            if(sign * ans > INT_MAX) return INT_MAX;
            if(sign * ans < INT_MIN) return INT_MIN;
            i++;
        }

        return (int)(sign * ans);
    }
};