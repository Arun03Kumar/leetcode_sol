class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "0";
        int count = 1;
        char curr = num[0];
        for(int i = 1; i < num.size(); i++) {
            if(num[i] == curr && count < 4) {
                count++;
            }
            else {
                curr = num[i];
                count = 1;
            }

            if(count == 3) {
                string temp(3, num[i]);
                int n = stoi(temp);
                if(n >= stoi(ans)) ans = temp;
            }
        }

        return ans == "0" ? "" : ans;
    }
};