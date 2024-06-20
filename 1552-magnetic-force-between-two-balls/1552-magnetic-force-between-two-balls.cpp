class Solution {
public:
    bool possible_to_place(vector<int> position, int m, int mid) {
        int prev = position[0], count = 1;
        for(int i = 1; i < position.size(); i++) {
            int curr = position[i];
            if(curr - prev >= mid) {
                count++;
                prev = curr;
            }
            if(count == m) break;
        }
        return count == m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); 
        // sort(begin(position), end(position));

        int min_force = 1, max_force = position[position.size() - 1] - position[0];
        int ans = 0;
        while(min_force <= max_force) {
            int mid = min_force + (max_force - min_force) / 2;
            if(possible_to_place(position, m, mid)) {
                ans = mid;
                min_force = mid + 1;
            }
            else {
                max_force = mid - 1;
            }
        }
        return ans;
    }
};