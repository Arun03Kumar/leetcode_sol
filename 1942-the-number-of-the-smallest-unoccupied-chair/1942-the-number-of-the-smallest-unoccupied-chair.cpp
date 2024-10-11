class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // Approach 1: Bruteforce
        // we create an array which stores the departure time of each friend
        // since it is given that arrival time will be unique so that we can search the target friend easily
        // then we can iterate for each index to check if we can assign that chair to the current friend

        int n = times.size();
        vector<int> chairs(n, -1);

        int target_arrival = times[targetFriend][0];

        sort(begin(times), end(times));

        for(int i = 0; i < n; i++) {
            int arrival = times[i][0];
            int departure = times[i][1];

            for(int j = 0; j < n; j++) {
                if(chairs[j] <= arrival) {
                    chairs[j] = departure;

                    if(arrival == target_arrival) {
                        return j;
                    }
                    break;
                }
            } 
        }

        return -1;
    }
};