class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // first convert the time string and minute string into integers
        // convert each time into minutes
        // sort the times now we need to just compare each adjecent elements only that will give the minmum time
        // it can be possible that wraparound time between first and last element is smaller than the rest
        // we need not check wrap around time for other elements because if first and last element dosent have minimum then no one will have.
        // to calculate wrap around we can subtract last element from 1440 then add the first element.

        int ans = INT_MAX;
        int n = timePoints.size();

        vector<int> minutes;
        for(int i = 0; i < timePoints.size(); i++) {
            string hour1 = timePoints[i].substr(0, 2);
            string min1 = timePoints[i].substr(3, 2);
            int h1 = stoi(hour1);
            int m1 = stoi(min1);

            minutes.push_back(h1 * 60 + m1);
        }

        sort(begin(minutes), end(minutes));

        for(int i = 1; i < minutes.size(); i++) {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }

        ans = min(ans, 1440 - minutes[n - 1] + minutes[0]);
        ans = min(ans, minutes[n - 1] - minutes[0]);

        return ans;
    }
};