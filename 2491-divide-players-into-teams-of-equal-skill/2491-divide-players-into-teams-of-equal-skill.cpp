class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // int n = skill.size();
        // int size = n / 2;
        // int sum = accumulate(begin(skill), end(skill), 0);

        // if(sum % size != 0) return -1;

        // int target = sum / size;

        // unordered_map<int, int> mp;
        // long long ans = 0;

        // for(int i = 0; i < n; i++) {
        //     int rem = target - skill[i];

        //     if(mp.find(rem) == mp.end()) {
        //         mp[skill[i]]++;
        //     }
        //     else {
        //         ans += skill[i] * rem;
        //         mp[rem]--;
        //         cout << rem << " " << mp[rem] << endl;
        //         if(mp[rem] == 0) {
        //             mp.erase(rem);
        //         }
        //     }
        // }
        
        // if(mp.size() > 0) return -1;
        // return ans == 0 ? -1 : ans;


        // Approach 2: sorting

        int n = skill.size();
        sort(begin(skill), end(skill));

        int i = 0, j = n - 1;
        int target = skill[i] + skill[j];
        long long ans = 0;

        while(i < j) {
            int sum = skill[i] + skill[j];

            if(sum != target) return -1;

            ans += (skill[i] * skill[j]);
            i++;
            j--;
        }

        return ans;

    }
};