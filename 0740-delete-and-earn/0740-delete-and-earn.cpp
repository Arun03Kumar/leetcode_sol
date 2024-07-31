class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        // so basically we create an array without any duplicates then sort it.
        // we also have frequency of each element, because if we choose that element to delete then we can do this frequency times and we earn freq*element
        // this is similar to house robber problem.
        // create a dp array, which tells that what can be maximum earned till dp[i]
        // so we try to fill this dp in bottom up fashion.
        // iterate over each element we can calculate it how much we can earn from this element by multiplying it with the freq.
        // we can check if previous element is one less than curr element then we can skip prev element and add second previous element. and chcek which is larger in the sum or previous element.

        unordered_map<int, int> freq;
        vector<int> nwd; //nums_without_duplicate
        for(int x: nums) {
            if(freq.find(x) == freq.end()) {
                nwd.push_back(x);
            }
            freq[x]++;
        }

        sort(begin(nwd), end(nwd));

        int n = nwd.size();

        if(n == 1) return nwd[0] * freq[nwd[0]];

        vector<int> dp(n, 0);

        dp[0] = nwd[0] * freq[nwd[0]];

        if(nwd[1] == nwd[0] + 1)
            dp[1] = max(dp[0], nwd[1] * freq[nwd[1]]);
        else {
            dp[1] = dp[0] + nwd[1] * freq[nwd[1]];
        }

        for(int i = 2; i < n; i++) {
            int curr_earn = nwd[i] * freq[nwd[i]];

            if(nwd[i] == nwd[i - 1] + 1) {
                dp[i] = max(curr_earn + dp[i - 2], dp[i - 1]);
            }
            else {
                dp[i] = curr_earn + dp[i - 1];
            }
        }

        return dp[n - 1];
    }
};