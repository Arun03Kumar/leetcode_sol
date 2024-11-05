class Solution {
public:
    const int M = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> vec(26, 0);
        for(char ch: s) {
            vec[ch - 'a']++;
        }

        for(int x: vec) cout << x << " ";

        long long prev = -1;
        // int ans = s.size();
        while(t--) {
            for(int i = 0; i < 26; i++) {
                // if(vec[i] > 0) {
                    long long temp = vec[i];
                    if(prev == -1) {
                        prev = temp;
                        vec[i] = 0;
                    }
                    else if(i == 25) {
                        vec[i] = prev % M;
                        prev = 0;

                        // ans += temp * 2;
                        vec[0] = (vec[0] % M + temp % M) % M;
                        vec[1] = (vec[1] % M + temp % M) % M;
                    }
                    else {
                        vec[i] = prev % M;
                        prev = temp;
                    }
                // }
            }
            cout << endl;
            for(int x: vec) cout << x << " ";
        }
        int ans = 0;
        for(int x: vec) {
            ans = (ans % M + x % M) % M;
        }

        return ans;
        // return accumulate(begin(vec), end(vec), 0) % M;
    }
};