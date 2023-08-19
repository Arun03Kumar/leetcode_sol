class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int max_=nums[n-1];
        int min_=nums[0];
        int res=max_-min_;
        for(int i=1;i<n;i++)
        {
            min_=min(nums[i]-k,nums[0]+k);

            max_=max(nums[i-1]+k,nums[n-1]-k);
            res=min(res,max_-min_);
        }
        return res; 
    }
};