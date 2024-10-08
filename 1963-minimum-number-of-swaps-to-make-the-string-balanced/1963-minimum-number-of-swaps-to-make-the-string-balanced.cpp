class Solution {
public:
    int minSwaps(string s) {
        // so we can get the count of maximum numbers of closing bracket because that will make string unbalanced
        // ex ]]][[[ here ] is at the start but it should be started with [
        // so we need to keep track of maximum of them 
        // but we can observe that if we swap one ] with [ it will make balance two brackets so we just need to divide it by 2 to get the answer

        int n = s.size();

        int ans = 0, sum = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == ']') {
                sum++;
            }
            else {
                sum--;
            }

            ans = max(ans, sum);
        }

        return (ans + 1) / 2;
    }
};