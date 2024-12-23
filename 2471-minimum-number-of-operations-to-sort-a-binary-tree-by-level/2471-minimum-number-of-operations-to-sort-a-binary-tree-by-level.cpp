/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(vector<int> &vec) {
        vector<int> temp = vec;
        sort(begin(temp), end(temp));
        int ans = 0;

        unordered_map<int, int> mp;
        for(int i = 0; i < vec.size(); i++) {
            mp[vec[i]] = i;
        }

        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == temp[i]) continue;
            else {
                int curr_idx = mp[temp[i]];
                mp[vec[i]] = curr_idx;
                swap(vec[i], vec[curr_idx]);
                ans++;
            }
        }

        return ans;
    }

    int minimumOperations(TreeNode* root) {
        // main problem is that you have an array and you just need to find the number of swaps needed to sort it
        // since it is given that there will be unique elements so we can leverage this
        // we can sort the array to know the exact position of each elements and then we could use a map to store there locations in sorted array
        // after then we could swap in the array and just increase the counter

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            while(size--) {
               TreeNode* front = q.front();
               q.pop();
               temp.push_back(front -> val);

               if(front -> left) q.push(front -> left); 
               if(front -> right) q.push(front -> right); 
            }

            ans += solve(temp);
        }

        return ans;
    }
};