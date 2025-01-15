class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // we can say answer is same is num1 if count is equal
        // if we want less count then just remove required set bits from lsb
        // if we want more bits then add some set bits to lsb where bit ins unset

        int curr = __builtin_popcount(num1);
        int req = __builtin_popcount(num2);


        if(curr == req) return num1;
        else if(curr < req) {
            for(int i = 0; i < 32 && curr < req; i++) {
                if((num1 & (1 << i)) == 0) {
                    num1 |= (1 << i);
                    curr++;
                }
            }
        }
        else {
            for(int i = 0; i < 32 && curr > req; i++) {
                if((num1 & (1 << i)) == 1) {
                    num1 &= ~(1 << i);
                    curr--;
                }
            }
        }

        return num1;
    }
};