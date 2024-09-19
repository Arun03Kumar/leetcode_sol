class Solution {
public:
    vector<int> recursion(string s) {
        vector<int> ans;

        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> res_left = recursion(s.substr(0, i));
                vector<int> res_right = recursion(s.substr(i + 1));

                for(int &x: res_left) {
                    for(int &y: res_right) {

                        if(s[i] == '+') {
                            ans.push_back(x + y);
                        }
                        else if(s[i] == '-') {
                            ans.push_back(x - y);
                        }
                        else {
                            ans.push_back(x * y);
                        }

                    }
                }
            }

        }

        if(ans.empty()) ans.push_back(stoi(s));

        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return recursion(expression);
    }
};