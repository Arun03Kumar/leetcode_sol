class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // Appraoch 1:
        // valid binary tree properties:
        // 1. every child should have only one parent
        // 2. there should be only one root
        // 3. there should be only one connected component

        // for validating first property we can use a map to store the parent of a child. so if any time we get any two parents of the child we can return false
        // for second condition we should first find a root
        // to find a root if we don't get parent of any node then it means that node is root, but if we get multiple such nodes then it means we have two roots so return false
        // also if we don't get any root then also return false because we need atleast one root

        // to check if we have one component then we can use any of BFS or DFS and count the visited node, if in one iteration if we get number of nodes equal to the n then it means there is only one component

        unordered_map<int, int> child_to_parent;  // to find the parent of a child node
        unordered_map<int, vector<int>> adj;  // this is to checking for connected components, for a given node we store the childrens of it

        for(int i = 0; i < n; i++) {

            int node = i;
            int left_child = leftChild[i];
            int right_child = rightChild[i];

            if(left_child != -1) {
                adj[node].push_back(left_child);

                if(child_to_parent.find(left_child) != child_to_parent.end()) {
                    return false;
                }
                else {
                    child_to_parent[left_child] = node;
                }
            }

            if(right_child != -1) {
                adj[node].push_back(right_child);

                if(child_to_parent.find(right_child) != child_to_parent.end()) {
                    return false;
                }
                else {
                    child_to_parent[right_child] = node;
                }
            }

        }

        int root = -1;
        // this is to check for one root
        for(int i = 0; i < n; i++) {
            if(child_to_parent.find(i) == child_to_parent.end()) {
                if(root != -1) { // if root != -1 means we already have a root but we are getting another one from the map
                    return false;
                }
                else {
                    root = i;
                }
            }
        }

        // if we don't get any root then it also not a valid binary tree
        if(root == -1) return false;


        // checking for single connected components
        // just do a bfs or dfs and count the nodes if it is same as n then return true else false

        queue<int> q;
        vector<int> visited(n, 0);

        int count = 1;
        q.push(root);
        visited[root] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int &child: adj[node]) {
                if(!visited[child]) {
                    visited[child] = 1;
                    q.push(child);
                    count++;
                }
            }
        }

        return count == n;

    }
};