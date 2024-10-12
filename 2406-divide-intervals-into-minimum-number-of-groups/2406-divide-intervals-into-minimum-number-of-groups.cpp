class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // using Priority queue
        // in interval based problem try to sort the given array
        // now we have to check if the starting value is greter than any previously seen ending points
        // so we can put this interval into that group
        // so we need to store the ending points of each group and we need a data structure which gives the minimum ending point 

        // if ending is not greater than top then it won't be greater than any other one because min heap keeps elements in sorted order
        // so if not then push ending point in pq to create a new group

        priority_queue<int, vector<int>, greater<int>> pq;

        sort(begin(intervals), end(intervals));

        for(vector<int> &x: intervals) {
            int start = x[0];
            int end = x[1];

            if(!pq.empty() && start > pq.top()) {
                pq.pop();
            }

            pq.push(end);
        }

        return pq.size();
    }
};