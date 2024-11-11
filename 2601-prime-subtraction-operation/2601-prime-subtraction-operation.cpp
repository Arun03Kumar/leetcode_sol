class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        // if you start from the end then just check that current element is less than the next element, if it is true then you don't have to think because that after that all will be in order means in increasing order
        // but if not the case then start from small prime number and make the current element just less than the next element, because if we reduce this number by larger then it won't be guranteed than in remaining array it will become less than reduced number 

        int n = nums.size();
        int max_num = *max_element(begin(nums), end(nums));
        vector<bool> is_prime(max_num + 1, true);
        is_prime[0] = is_prime[1] = false;

        for(int i = 2; i <= max_num; i++) {
            if(is_prime[i]) {
                for(int j = i * 2; j <= max_num; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        for(bool x: is_prime) cout << x << " ";

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) continue;

            for(int j = 2; j < nums[i]; j++) {
                if(is_prime[j]) {
                    if(nums[i] - j < nums[i + 1]) {
                        nums[i] = nums[i] - j;
                        break;
                    }
                }
            }

            if(nums[i] >= nums[i + 1]) return false;
        }

        return true;
    }
};