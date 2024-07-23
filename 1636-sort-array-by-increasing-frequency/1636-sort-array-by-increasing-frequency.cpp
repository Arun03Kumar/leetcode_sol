class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x: nums) {
            freq[x]++;
        }

        auto comp = [&](int x, int y) {
            if(freq[x] == freq[y]) {
                return x > y;
            }

            return freq[x] < freq[y];
        };

        sort(begin(nums), end(nums), comp);

        return nums;
    }
};