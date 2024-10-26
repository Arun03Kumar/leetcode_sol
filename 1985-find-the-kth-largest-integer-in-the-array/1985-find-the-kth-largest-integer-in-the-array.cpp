class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq;

        for(string s: nums) {
            int n = stoll(s);
            pq.push(n);

            if(pq.size() > k) pq.pop();
        } 

        // string ans = to_string()
        return to_string(pq.top());
    }
};