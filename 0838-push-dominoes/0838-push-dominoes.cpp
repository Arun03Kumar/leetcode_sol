class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        string new_str = 'L' + dominoes + 'R';
        int l = -1, r;
        vector<pair<int, int>> seg;
        for(int i = 0; i <= n; i++) {
            if(new_str[i] != '.') {
                if(l == -1) l = i;
                else {
                    r = i;
                
                    seg.push_back({l, r});

                    l = r;
                }
            }
        }
        seg.push_back({l, n + 1});

        for(auto x: seg) {
            cout << x.first << " " << x.second << endl;
        }

        for(auto &x: seg) {

            int l_idx = x.first, r_idx = x.second;

            char at_l_idx = new_str[l_idx];
            char at_r_idx = new_str[r_idx];

            if(at_l_idx == 'L' && at_r_idx == 'L') {
                for(int i = l_idx + 1; i < r_idx; i++) {
                    new_str[i] = 'L';
                }
            }
            else if(at_l_idx == 'R' && at_r_idx == 'R') {
                for(int i = l_idx + 1; i < r_idx; i++) {
                    new_str[i] = 'R';
                }
            }
            else if(at_l_idx == 'R' && at_r_idx == 'L') {
                int len = r_idx - l_idx - 1;
                if(len % 2 == 0) {
                    for(int i = l_idx + 1; i <= l_idx + len / 2; i++) {
                        new_str[i] = 'R';
                    }
                    for(int i = l_idx + len / 2 + 1; i < r_idx; i++) {
                        new_str[i] = 'L';
                    }
                }
                else {
                    for(int i = l_idx + 1; i <= l_idx + len / 2; i++) {
                        new_str[i] = 'R';
                    }
                    for(int i = l_idx + len / 2 + 2; i < r_idx; i++) {
                        new_str[i] = 'L';
                    }
                }
            }
        }

        return new_str.substr(1, n);
    }
};