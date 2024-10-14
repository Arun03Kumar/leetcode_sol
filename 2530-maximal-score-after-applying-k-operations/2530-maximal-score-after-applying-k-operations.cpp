class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq;

        for(int &x: nums) {
            pq.push(x);
        }

        long long ans = 0;
        while(k--) {
          int top = pq.top();
          pq.pop();

          ans += top;
          pq.push(ceil(top / 3.0));  
        }

        return ans;
    }
};