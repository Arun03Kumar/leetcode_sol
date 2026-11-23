class Solution {
public:
    void recursion(vector<int>& candidates,int target,vector<int>&temp,int i,set<vector<int>>&ans)
    {
        if(i==candidates.size())
        {
            if(target==0)
            {
                ans.insert(temp);
                return;
            }
            return;
        }
        if(candidates[i]<=target)
        {
            temp.push_back(candidates[i]);
            // int t = i + 1;
            // while(t < candidates.size() && candidates[t] == candidates[i]) t++;
            recursion(candidates,target-candidates[i],temp,i + 1,ans);
            temp.pop_back();
        }
        int t = i + 1;

        while(t < candidates.size() &&
              candidates[t] == candidates[i]) {
            t++;
        }
        recursion(candidates,target,temp,t,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>>ans;
        vector<vector<int>>final_ans;
        vector<int>temp;
        recursion(candidates,target,temp,0,ans);
        for(auto it:ans)
        {
            final_ans.push_back(it);
        }
        return final_ans;
    }
};