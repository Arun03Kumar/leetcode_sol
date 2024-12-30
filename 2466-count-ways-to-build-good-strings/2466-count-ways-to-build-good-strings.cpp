class Solution {
public:
    int recursion(int &l, int &h, int &z, int &o, int count) {
        if(count > h) return 0;

        int one = 0, zero = 0;
        if(count + o < l) {
            one = recursion(l, h, z, o, count + o);
        }
        if(count + z < l) {
            zero = recursion(l, h, z, o, count + z);
        }

        if(count + o >= l && count + o <= h) {
            one = 1 + recursion(l, h, z, o, count + o);
        }

        if(count + z >= l && count + z <= h) {
            zero = 1 + recursion(l, h, z, o, count + z);
        }

        return one + zero;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        return recursion(low, high, zero, one, 0);
    }
};