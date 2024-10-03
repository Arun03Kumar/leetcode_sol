class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos = 0, neg = 0;

        for(int &x: nums) {
            if(x == 0) return 0;
            if(x > 0) pos++;
            else neg++;
        }

        if(neg % 2 == 0) return 1;
        else return -1;
    }
};