class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26, 0);
        for(int i = 0; i < word.size(); i++) {
            char x = word[i];
            arr[x - 'a']++;
        }

        sort(arr.begin(), arr.end(), greater<int>());
        // for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
        int i = 0, count = 0, ans = 0;
        while(i < arr.size()) {
            if(i % 8 == 0) {
                count++;
            }

            ans += arr[i] * count;
            i++;
        }

        return ans;
    }
};