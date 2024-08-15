class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> freq;
        for(int x: bills) {
            freq[x]++;
            if(x == 10) {
                if(freq[5] < 0) return false;
                freq[5]--;   
            }
            else if(x == 20) {
                if(freq[5] < 0 || freq[10] < 0) return false;
                if(freq[5] >= 1 && freq[10] >= 1) {
                    freq[5]--;
                    freq[10]--;
                }
                else if(freq[5] >= 3) {
                    freq[5] -= 3;
                }
                else {
                    return false;
                }
            }
        }

        // for(int x: bills) {
            
        // }

        return true;
    }
};