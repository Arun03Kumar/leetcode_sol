class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // Approach : Difference Array Technique
        // so what we can we can take an array and update the starting position index with addition of 1 if shift is forward else add -1
        // but we also need the ending point so what we can do we can go to endIndex + 1, and subtract -1
        // now if we take cummulative sum of array it will give us the update of +1 or -1 based on shift direction from start index to end index

        int n = s.size();
        vector<int> diff(n, 0);

        for(vector<int> &q: shifts) {
            int l = q[0];
            int r = q[1];
            int dir = q[2];

            int shift;
            if(dir == 0) shift = -1;
            else shift = 1;

            diff[l] += shift;
            if(r + 1 < n) diff[r + 1] -= shift;
        }

        for(int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        for(int i = 0; i < n; i++) {
            int shift = diff[i] % 26; // diff array value can be very large

            if(shift < 0) shift += 26; // if it -ve then we have to make it +ve

            s[i] = ((s[i] - 'a') + shift) % 26 + 'a';
        }

        return s;
    }
};