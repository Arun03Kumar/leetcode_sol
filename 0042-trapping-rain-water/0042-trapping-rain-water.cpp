class Solution {
public:
    int trap(vector<int>& height) {
        // O(N) time ans space complexity approach
        int n = height.size();
        // vector<int> left_max(n), right_max(n);
        // left_max[0] = 0; 
        // right_max[n-1] = 0;
        // for(int i = 1; i < height.size(); i++) {
        //     left_max[i] = max(height[i-1], left_max[i-1]);
        //     right_max[n-i-1] = max(height[n-i], right_max[n-i]);
        // }
        // int ans = 0;
        // for(int i = 0; i < n; i++) {
        //     int x = min(left_max[i], right_max[i]);
        //     if(x - height[i] >= 0) {
        //         ans += x - height[i];
        //     }
        // }
        // return ans;

        // O(1) space complexity approach, two pointer
        int l = 0, r = n-1, left_max = height[0], right_max = height[n-1];
        int ans = 0;
        while(l < r) {
            if(left_max < right_max) {
                if(left_max - height[l] > 0)
                    ans += left_max - height[l];
                l++;
                left_max = max(left_max, height[l]);
            }
            else {
                if(right_max - height[r] > 0)
                    ans += right_max - height[r];
                r--;
                right_max = max(right_max, height[r]);
            }
        }
        return ans;
    }
};