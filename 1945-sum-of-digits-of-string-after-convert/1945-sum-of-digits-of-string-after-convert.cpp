class Solution {
public:
    void add(int x, int &sum) {
        int temp = 0;
        while(x > 0) {
            int rem = x % 10;
            x /= 10;
            temp += rem;
        }

        sum += temp;
    }
    int getLucky(string s, int k) {
        int n = s.size();
        vector<int> arr(n);

        for(int i = 0; i < n; i++) {
            arr[i] = s[i] - 'a' + 1;
            cout << arr[i] << " ";
        }

        int sum = 0;
        for(int &x: arr) {
            add(x, sum);
        }

        int ans = sum;
        while(--k) {
            int temp2 = 0;
            add(ans, temp2);
            ans = temp2;
        }

        return ans;
    }
};