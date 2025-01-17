class Solution {
public:
    bool is_valid(vector<int> &derived, vector<int> &curr) {
        int n = derived.size();
        for(int i = 1; i < n; i++) {
            if(i == n - 1) {
                return (curr[n - 1] ^ curr[0]) == derived[n - 1];
            }

            if(derived[i] == 1) curr.push_back(1 - curr.back());
            else {
                curr.push_back(curr.back());
            }
        }

        return true;
    }

    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        if(n == 1 && derived[0] == 1) return false;
        if(n == 1 && derived[0] == 0) return true;

        vector<int> curr1, curr2;
        if(derived[0] == 1) {
            curr1.push_back(1);
            curr1.push_back(0);
            curr2.push_back(0);
            curr2.push_back(1);
        }
        else {
            curr1.push_back(1);
            curr1.push_back(1);
            curr2.push_back(0);
            curr2.push_back(0);
        }

        bool a = is_valid(derived, curr1);
        bool b = is_valid(derived, curr2);

        return a || b;
    }
};