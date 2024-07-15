class Solution {
public:
    // indegree means people trust him, so indegree of judge must be equal to n-1 and outdegree of judge must be 0
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1);
        vector<int> outdegree(n + 1);

        for(auto x: trust) {
            outdegree[x[0]]++;
            indegree[x[1]]++;
        }

        for(int i = 1; i <= n; i++) {
            if(indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};