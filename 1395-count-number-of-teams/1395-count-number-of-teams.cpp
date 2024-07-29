class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        int ans = 0;

        for(int i = 1; i < n - 1; i++) {

            int left_larger = 0;
            int left_smaller = 0;
            int right_larger = 0;
            int right_smaller = 0;

            for(int j = i - 1; j >= 0; j--) {
                if(rating[j] < rating[i]) {
                    left_smaller++;
                }
                else if(rating[j] > rating[i]) {
                    left_larger++;
                }
            }

            for(int j = i + 1; j < n; j++) {
                if(rating[j] < rating[i]) {
                    right_smaller++;
                }
                else if(rating[j] > rating[i]) {
                    right_larger++;
                }
            }

            ans += (left_smaller * right_larger) + (left_larger * right_smaller);

        }


        return ans;
    }
};