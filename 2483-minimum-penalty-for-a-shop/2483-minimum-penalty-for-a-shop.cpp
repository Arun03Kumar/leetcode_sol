class Solution {
public:
    int bestClosingTime(string customers) {
        // Brute force O(n^2)
        // for each index we assue from this index shop is close 
        // so count number of Y after that index and count number of No before that index
        // but it is also given that shop can closed at n hour so we need to also check in complete array the count of No

        int n = customers.size();
        int ans = 0, min_penalty = INT_MAX;
        for(int i = 0; i < n; i++) {
            
            int count = 0;
            for(int j = i; j < n; j++) {
                if(customers[j] == 'Y') count++;
            }

            for(int j = i - 1;  j >= 0; j--) {
                if(customers[j] == 'N') count++;
            }

            if(count < min_penalty) {
                ans = i;
                min_penalty = count;
            }

        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'N') count++;
        }

        if(count < min_penalty) {
            ans = n;
            min_penalty = count;
        }

        return ans;
    }
};