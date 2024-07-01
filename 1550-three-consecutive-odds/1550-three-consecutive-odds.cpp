class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0, l = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(i < 3) {
                if(arr[i] % 2) {
                    count++;
                }
            }
            else {
                if(arr[i] % 2) count++;
                if(arr[l] % 2) {
                    count--;
                    l++;
                }
            }
            if(count == 3) return true;
        }
        return count == 3;
    }
};