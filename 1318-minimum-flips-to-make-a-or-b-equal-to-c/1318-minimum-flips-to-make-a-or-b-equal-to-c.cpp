class Solution {
public:
    int minFlips(int a, int b, int c) {
        // we can check for each bit in all the numbers.

        // if right most bit of c is 0 then it is required that both rightmost bits of a and b should also be 0.

        // if right most bit of c is one then it requires that any one of the a and b should have the rightmost bit as 1.

        // we can find the right most bit by (num&1), by doing and operation with 1.

        int flips = 0;
        while(a != 0 || b != 0 || c != 0) {

            int right_most_of_c = (c&1);

            if(right_most_of_c == 0) { // it means both bits of a and b should also be 0;

               if((a&1) == 1) flips++;
               if((b&1) == 1) flips++; 

            }
            else {

                if((a&1) == 0 && (b&1) == 0) flips++;

            }

            a = a >> 1;
            b = b >> 1;
            c >>= 1;

        }

        return flips;
    }
};