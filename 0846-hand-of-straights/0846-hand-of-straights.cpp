class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // next element should be +1, not +2 or something it should be consecutive
        int n = hand.size();

        if(n % groupSize != 0) return false;

        map<int, int> freq;
        for(int &x: hand) freq[x]++;

        while(!freq.empty()) {

            int curr = freq.begin() -> first;

            for(int i = 0; i < groupSize; i++) {

                if(freq[curr + i] == 0) return false;

                freq[curr + i]--;
                if(freq[curr + i] < 1) {
                    freq.erase(curr + i);
                }

            }

        }

        return true;

    }
};