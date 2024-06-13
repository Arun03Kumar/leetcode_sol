class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int ans = 0;
        for(int i = seats.size() - 1; i >= 0; i--) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};