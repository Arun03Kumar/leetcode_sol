class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<pair<char, int> > arr;
        for(int i = 0; i < colors.size(); i++) {
            arr.push_back(make_pair(colors[i], neededTime[i]));
            // sort(arr.begin(), arr.end());
        }
        int l = 0, max_elem = 0, total_sum = 0, ans = 0;
            while(l < arr.size()) {
                int r = l + 1, flag = 0;
                while(r < arr.size() && arr[l].first == arr[r].first) {
                    total_sum += arr[r].second;
                    max_elem = max(arr[r].second, max_elem);
                    r++;
                    flag = 1;
                }
                if(flag) {
                    total_sum += arr[l].second;
                    max_elem = max(arr[l].second, max_elem);
                    ans += (total_sum - max_elem);
                    l = r;
                    max_elem = 0;
                    total_sum = 0;
                }
                else{
                    l++;
                }
            }
            return ans;
    }
};