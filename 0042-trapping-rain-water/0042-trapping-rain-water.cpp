class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        left_max[0] = 0; 
        right_max[n-1] = 0;
        for(int i = 1; i < height.size(); i++) {
            left_max[i] = max(height[i-1], left_max[i-1]);
            right_max[n-i-1] = max(height[n-i], right_max[n-i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x = min(left_max[i], right_max[i]);
            if(x - height[i] >= 0) {
                ans += x - height[i];
            }
        }
        return ans;
    }
};