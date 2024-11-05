class Solution {
public:
    int ans = 0;
    

    void solve(string s) {
        int e = 0, o = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i&1) {
                o += s[i] - '0';
            }
            else {
                e += s[i] - '0';
            }
        }
        cout << e << " " << o;
        if(e == o) ans++;
    }
   void backtracking(unordered_map<char, int> &mp, string &curr, int &n) {
        if(curr.size() == n) {
            // ans.push_back(curr);
            solve(curr);
            return;
        }

        for(auto &[t, count]: mp) {
            if(count == 0) continue;

            curr.push_back(t);
            mp[t]--;
            backtracking(mp, curr, n);

            curr.pop_back();
            mp[t]++;
        }
    }
    // ---------------------------Optimal-------------------------------
    int M = 1e9+7;
    typedef long long ll;

    vector<int> freq;
    vector<int> fact;
    vector<int> inverse_fact;
    int n;
    int target;

    vector<vector<vector<int>>> dp;

    ll binary_exponentiation(ll a, ll b, ll m) {
        ll res = 1;
        while(b > 0) {
            if(b & 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }

        return res;
    }

    int recursion(int num, int odd_size, int curr_sum) {
        if(num == 10) {
            if(odd_size == n / 2 && curr_sum == target) {
                int even_size = n - odd_size;
                return (1LL * fact[even_size] * fact[odd_size]) % M;
            }

            return 0;
        }

        if(curr_sum > target) return 0;

        int ans = 0;
        for(int i = 0; i <= min(freq[num], n / 2 - odd_size); i++) {
            int even_cnt = freq[num] - i;
            int temp = recursion(num + 1, i + odd_size, curr_sum + i * num) % M;
            int permutations = (1LL * inverse_fact[i] * inverse_fact[even_cnt]) % M;
            ans = (ans + (temp * permutations)) % M;
        }

        return ans;
    }

    int memoization(int num, int odd_size, int curr_sum) {
        if(num == 10) {
            if(odd_size == n / 2 && curr_sum == target) {
                int even_size = n - odd_size;
                return (1LL * fact[even_size] * fact[odd_size]) % M;
            }

            return 0;
        }

        if(curr_sum > target) return 0;

        if(dp[num][odd_size][curr_sum] != -1) return dp[num][odd_size][curr_sum];

        int ans = 0;
        for(int i = 0; i <= min(freq[num], n / 2 - odd_size); i++) {
            int even_cnt = freq[num] - i;
            int temp = memoization(num + 1, i + odd_size, curr_sum + i * num) % M;
            int permutations = (1LL * inverse_fact[i] * inverse_fact[even_cnt]) % M;
            ans = (0LL + ans + (temp * 1LL * permutations) % M) % M;
        }

        return dp[num][odd_size][curr_sum] = ans;
    }

    int countBalancedPermutations(string num) {
        // Approach 1: Bruteforce
        // generating all permutations then summing the values at even and odd positions

        // string curr;

        // unordered_map<char, int> mp;
        // int n = num.size();

        // for(char x: num) mp[x]++;

        // backtracking(mp, curr, n);
        // return (ans)%M;

        // Optimal Approach: using DP, Binary Exponentitaion, 
        // Requirements and Observations:
        // 1. we need to divide the frequecny count of numbers in the even set and the odd set
        // 2. there can be only 10 digits possible from 0-9, so freq table will contains only 10 elements
        // 3. sum of the given number should be even, because then only it can be equally divided, we can find the sum then the target value for odd set and even set would be sum/2
        // 4. so we can store the frequency of digits and iterate over each one, so for each element we can have many choices to select some the freq count and put them in even set and rest in odd set or vice versa.
        // 5. lets we have decided our even set and the odd set then we can have the permutations of these set as well because there sum won't be changed if we change the order of numbers
        // 6. this is combinatorail problem, if set contains n number then total number of ways that can be permutated in n!
        // 7. but it may possible that some numbers are repeated in that case let two numbers are repeted x times and y times in that case, total number of ways will be n!/(x!*y!)
        // 8. permutations require computation of factorials, so we can precompute it
        // 9. if there are n numbers in even or odd set that represents count of numbers which can be only uptp 80 as given in constraints so we can precompute factorails upto then 
        // 10. but in permuations we also have to divide with the factorial and then find the mod of it, so we know in division we can not simply calculate the mod operations so for that we have to use Fermat's little theorem and inverse modulo, so we know (a inverse)%m = a^(m - 2)
        // 11. so using this (1/i!)%m === (i! inverse) % m === (i! ^ (m - 2)) %m and we can calculate it using Binary Exponentiation
        // 12. in code this is done is two parts when recursion returns it only take care of the numerator part factorial
        // 13. after that below in the loop we can find the number of repeating character as the value of i and that can be used to find inverse fact
        

        n = num.size();
        freq.resize(10, 0);
        fact.resize(n + 1, 1);
        inverse_fact.resize(n + 1, 1);

        int sum = 0;
        for(char ch: num) {
            freq[ch - '0']++;
            sum += ch - '0';
        }

        if(sum % 2 == 1) return 0; // can not be equally divided

        target = sum / 2;
        for(int i = 1; i <= n; i++) {
            fact[i] = (1LL * fact[i - 1] * i) % M;
            inverse_fact[i] = binary_exponentiation(fact[i], M - 2, M) % M;
        }

        // return recursion(0, 0, 0);

        dp.resize(10, vector<vector<int>>(n / 2 + 1, vector<int>(target + 1, -1)));
        return memoization(0, 0, 0);

    }
};