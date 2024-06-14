class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int> b1, b2;
        int l = 0, r = 0, ans = 0;
        while(r < fruits.size()) {
            if(!b1.empty() && fruits[r] == b1[b1.size() - 1]) {
                b1.push_back(fruits[r]);
            }
            else if(!b2.empty() && fruits[r] == b2[b2.size() - 1]) {
                b2.push_back(fruits[r]);
            }
            else if(b1.empty()) {
                b1.push_back(fruits[r]);
            }
            else if(b2.empty()) {
                b2.push_back(fruits[r]);
            }
            else {
                while(!b1.empty() && !b2.empty()) {
                    if(fruits[l] == b1[b1.size() - 1]) {
                        b1.pop_back();
                    }
                    else{
                        b2.pop_back();
                    }
                    l++;
                }
                if(b1.empty()) {
                    b1.push_back(fruits[r]);
                }
                else if(b2.empty()) {
                    b2.push_back(fruits[r]);
                }
            }
            ans = max(ans, r - l + 1);
            cout << ans << " " << l << " " << r << endl;
            r++;
        }
        return ans;
    }
};