class Solution {
public:
    string digitSum(string s, int k) {
        string temp = s;

        while(temp.size() > k) {
            // cout << temp << endl;
            int j = 0;
            int cnt = 0;
            int curr_sum = 0;
            string curr_ans = "";
            while(j < temp.size()) {
                curr_sum += temp[j] - '0';
                cnt++;
                // cout << temp[j] << " ";
                if(cnt == k) {
                    curr_ans += to_string(curr_sum);
                    curr_sum = 0;
                    cnt = 0;
                    cout << curr_ans << " ";
                }
                j++;
            }
            if(curr_sum > 0) {
                curr_ans += to_string(curr_sum);
            }
            else {
                if(temp.size() % k != 0 && temp.back() == '0' && curr_sum == 0) curr_ans.push_back('0');
            }
            temp = curr_ans;
            cout << endl;
            // cout << temp << endl;
        }

        return temp;
    }
};