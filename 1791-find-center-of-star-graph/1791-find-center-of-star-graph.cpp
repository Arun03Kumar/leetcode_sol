class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x1 = edges[0][0], x2 = edges[0][1];
        int x3 = edges[1][0], x4 = edges[1][1];
        if(x1 == x3) return x3;
        else if(x1 == x4) return x4;
        else return x2;
    }
};