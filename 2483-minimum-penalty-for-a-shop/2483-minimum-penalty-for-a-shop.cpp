class Solution {
public:
    int bestClosingTime(string customers) {
        // Brute force O(n^2)
        // for each index we assue from this index shop is close 
        // so count number of Y after that index and count number of No before that index
        // but it is also given that shop can closed at n hour so we need to also check in complete array the count of No

        // int n = customers.size();
        // int ans = 0, min_penalty = INT_MAX;
        // for(int i = 0; i < n; i++) {
            
        //     int count = 0;
        //     for(int j = i; j < n; j++) {
        //         if(customers[j] == 'Y') count++;
        //     }

        //     for(int j = i - 1;  j >= 0; j--) {
        //         if(customers[j] == 'N') count++;
        //     }

        //     if(count < min_penalty) {
        //         ans = i;
        //         min_penalty = count;
        //     }

        // }

        // int count = 0;
        // for(int i = 0; i < n; i++) {
        //     if(customers[i] == 'N') count++;
        // }

        // if(count < min_penalty) {
        //     ans = n;
        //     min_penalty = count;
        // }

        // return ans;

        // Approach 2: we can optimize this by calculating the number of N in the left of each char in string
        // and number of Y in the right side of it;
        // then simillar to above approach
        // also consider the last case where take care of whole array

        // int n = customers.size();
        // vector<int> left(n, 0), right(n, 0);

        // for(int i = 1; i < n; i++) {
        //     if(customers[i - 1] == 'N') {
        //         left[i] = left[i - 1] + 1;
        //     }
        //     else {
        //         left[i] = left[i - 1];
        //     }
        // }

        // if(customers[n - 1] == 'Y') right[n - 1] = 1;
        // for(int i = n - 2; i >= 0; i--) {
        //     if(customers[i] == 'Y') {
        //         right[i] = right[i + 1] + 1;
        //     }
        //     else {
        //         right[i] = right[i + 1];
        //     }
        // }

        // int ans = 0, penalty = INT_MAX;
        // for(int i = 0; i < n; i++) {
        //     int pen = left[i] + right[i];
        //     if(pen < penalty) {
        //         penalty = pen;
        //         ans = i;
        //     }
        // }

        // int count = 0;
        // for(int i = 0; i < n; i++) {
        //     if(customers[i] == 'N') count++;
        // }

        // if(count < penalty) {
        //     ans = n;
        //     penalty = count;
        // }

        // return ans;


        // Appraoch 3: we can use sliding window
        // first we create the window of whole array
        // then we can reduce it from the start which tells what happens if we close at that index;
        // if we have a yes at the current index it means total penalty decreases but if we have a no then current penalty increases
        
        int n = customers.size();
        int yes = 0, no = 0;

        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') yes++;
            else no++;
        }

        int penalty = yes, i = 1, min_penalty = yes;
        int ans = 0;

        while(i <= n) {
            if(customers[i - 1] == 'Y') {
                penalty--;
            }
            else {
                penalty++;
            }

            if(penalty < min_penalty) {
                min_penalty = penalty;
                ans = i;
            }

            i++;
        }

        return ans;
    }
};