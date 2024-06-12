class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0, sum = 0, avg, ans = 0;;
        for(int i = 0; i < arr.size(); i++) {
            if(i < k) {
                sum += arr[i];
                avg = sum / (i + 1);
            }
            else {
                sum += arr[i];
                sum -= arr[l++];
                avg = sum / k;
            }
            if(avg >= threshold && i >= k - 1) {
                ans++;
            }
        }
        return ans;
    }
};