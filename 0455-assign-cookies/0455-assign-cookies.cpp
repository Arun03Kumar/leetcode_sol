class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // vector<int> g_vec = g, s_vec = s;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = g.size() - 1, j = s.size() - 1, count = 0;
        while(j >= 0 && i >= 0) { 
            if(s[j] < g[i]) {
                i--;
            }
            else {
                count++;
                i--;
                j--;
            }
        }
        return count;
    }
};