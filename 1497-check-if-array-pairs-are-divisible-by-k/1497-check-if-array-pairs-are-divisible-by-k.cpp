class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // if (a+b)%k==0 then a%k + b%k should be equal to k itself.
        // so just take the frequency count of each remainder
        // now we just have to find if other half of a remainder exists or not simillar to two sum problem
        // but for remainder 0 we wont be having any counter parts because the no remainder would be equal to k.
        // so we just have to check if frequency of 0 is even because then we can pair all the remainder elements with 0

        unordered_map<int, int> rem_freq;

        for(int &x: arr) {
            int rem = (x % k + k) % k; // for handling -ve cases
            rem_freq[rem]++;
        }

        if(rem_freq[0] % 2 != 0) {
            return false;
        }

        for(int i = 1; i <= k / 2; i++) {
            int counter_half = k - i;
            if(rem_freq[i] != rem_freq[counter_half]) {
                return false;
            }
        }

        return true;
    }
};