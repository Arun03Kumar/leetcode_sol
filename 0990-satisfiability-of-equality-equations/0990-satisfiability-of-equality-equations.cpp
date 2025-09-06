class Solution {
public:
    vector<int> parent, rank;
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);

        if(par_x == par_y) return;

        if(rank[par_x] > rank[par_y]) parent[par_y] = par_x;
        else if(rank[par_x] < rank[par_y]) parent[par_x] = par_y;
        else {
            parent[par_x] = par_y;
            rank[par_y]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i < 26; i++) parent[i] = i;

        for(string &s: equations) {
            int x = s[0] - 'a';
            int y = s[3] - 'a';

            if(s[1] == '=') Union(x, y);
        }
        for(string &s: equations) {
            int x = s[0] - 'a';
            int y = s[3] - 'a';

            int par_x = find(x);
            int par_y = find(y);

            if(s[1] == '!' && par_x == par_y) return false;
        }

        return true;
    }
};