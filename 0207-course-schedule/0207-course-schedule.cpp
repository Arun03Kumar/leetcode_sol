class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int> > adj;
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        vector<int> indegree(numCourses, 0), visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(int x: adj[i]) {
                indegree[x]++;
            }
        }

        queue<int> q;
        int count = 0;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(int x: adj[front]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    q.push(x);
                    count++;
                }
            }
        }
        if(count == numCourses) return true;
        return false;
    }
};