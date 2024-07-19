class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x) {
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);

        if(par_x == par_y) return;

        if(size[par_x] >= size[par_y]) {
            parent[par_y] = par_x;
            size[par_x]++;
        }
        else {
            parent[par_x] = par_y;
            size[par_y]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // treat indexes as nodes and map mails to these indexes, so when we get same mails from two different indexes we merged two indexes into one using union.

        //so when we merge the mails to their respective names we find the parent and then merge into them.

        // 

       int n = accounts.size();
       parent.resize(n);
       size.resize(n, 0);

       for(int i = 0; i < n; i++) {
            parent[i] = i;
       } 

        unordered_map<string, int> mail_to_name_idx;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if(mail_to_name_idx.find(mail) == mail_to_name_idx.end()) {
                    mail_to_name_idx[mail] = i;
                }
                else {
                    Union(i, mail_to_name_idx[mail]);
                }
            } 
        }

        vector<string> merged[n];
        for(auto it: mail_to_name_idx) {
            string mail = it.first;
            int idx = it.second;

            int par_idx = find(idx);
            merged[par_idx].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {

            if(merged[i].size() == 0) continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            sort(merged[i].begin(), merged[i].end());
            temp.insert(temp.end(), merged[i].begin(), merged[i].end());

            ans.push_back(temp);
        }

        return ans;

    }
};