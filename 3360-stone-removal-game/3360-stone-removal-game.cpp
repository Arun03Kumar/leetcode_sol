class Solution {
public:
    bool canAliceWin(int n) {
        bool is_alice = false;

        int x = 10;

        while(n >= x) {
            is_alice = !is_alice;
            n -= x;
            x--;
        }

        return is_alice;
    }
};
