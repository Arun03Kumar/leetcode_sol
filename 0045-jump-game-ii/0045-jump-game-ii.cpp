class Solution {
public:
int solve(vector<int> &arr, int idx, int n, vector<int> &dp, int count) {
   if(idx == n) return dp[n] = 0;
   if(arr[idx] == 0) return dp[idx] = 9999999;
   int temp = INT_MAX;
   for(int i = 1; i<= arr[idx]; i++){
       int x;
       if(idx+i <= n){
           if(dp[idx+i] != -1) x = dp[idx+i];
           else  x =  solve(arr, idx+i, n, dp, count);
       }
       temp = min(x+1, temp);
   }
   return dp[idx] = temp;
}
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int x = solve(nums, 0, nums.size() - 1, dp, 0);
        return x;
    }
};