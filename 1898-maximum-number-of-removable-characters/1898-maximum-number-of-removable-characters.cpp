class Solution {
public:
    bool check(string s, string p, vector<int> arr, int k) {
        //for doing the check we can either remove the characters or we can simply replace it with an arbitrary characters which can never be match with any character in the subsequence.

        // we need to take two pointer starting with 0, now if they match increase both else increase only pointer for s, because we need to check id p is present in s which also follows the charachters present in s as same order in p.
        for(int i = 0; i < k; i++) {
            s[arr[i]] = '*';
        }
        int i = 0, j = 0;
        while(i < s.size() && j < p.size()) {
            if(s[i] == p[j]) i++, j++;
            else i++;
        }
        return j == p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        //we need to do iterate over each element in removable and remove that element from the string s then check whether p is a subsequence or not, but instead of doing linear search we can optimize it by doing a binary search over the indexes and remove all element till that index then check if the string p is subsequence or not, if it is still a subsequence it means there may be some larger index possible so move the low pointer else move the high pointer.
        int low = 0, high = removable.size(), ans = removable.size();
        while(low <= high) {
            int mid = (low + high) / 2;
            if(check(s, p, removable, mid)) { 
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};