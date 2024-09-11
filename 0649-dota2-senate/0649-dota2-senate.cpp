class Solution {
public:
    bool is_removal_from_left(string &s, char ch, int idx) {
        bool loop_around = false;

        while(true) {

            if(idx == 0) loop_around = true;

            if(s[idx] == ch) {
                s.erase(begin(s) + idx);
                break;
            }

            idx = (idx + 1) % s.size();

        }

        return loop_around;
    }

    void is_removed_from_left2(string &s, char ch, int idx, vector<bool> &is_removed) {

        while(true) {

            if(s[idx] == ch && is_removed[idx] == false) {
                is_removed[idx] = true;
                break;
            }

            idx = (idx + 1) % s.size();

        }

    }

    string predictPartyVictory(string senate) {
        // Brute force
        // its just a implementation
        // only check if next element is deleted from the left part of the string if yes then decress the index by 1

        // int r_count = count(begin(senate), end(senate), 'R');
        // int d_count = senate.size() - r_count;

        // int idx = 0;

        // while(r_count > 0 && d_count > 0) {

        //     if(senate[idx] == 'R') {

        //         bool check_removal = is_removal_from_left(senate, 'D', (idx + 1) % senate.size());
        //         d_count--;
        //         if(check_removal) idx--;

        //     }
        //     else {
        //         bool check_removal = is_removal_from_left(senate, 'R', (idx + 1) % senate.size());
        //         r_count--;
        //         if(check_removal) idx--;
        //     }

        //     idx = (idx + 1) % senate.size();

        // }

        // if(r_count == 0) return "Dire";
        // return "Radiant";


        // Approach 2: better 
        // since erasing from a string is O(n) so we are ignoring to remove from string and using a array to store if the index is removed or not

        int n = senate.size();
        int r_count = count(senate.begin(), senate.end(), 'R');
        int d_count = n - r_count;

        vector<bool> is_removed(n, false);

        int idx = 0;

        while(r_count > 0 && d_count > 0) {

            if(is_removed[idx] == false) {

                if(senate[idx] == 'R') {
                    is_removed_from_left2(senate, 'D', (idx + 1) % n, is_removed);
                    d_count--;
                }
                else {
                    is_removed_from_left2(senate, 'R', (idx + 1) % n, is_removed);
                    r_count--;
                }

            }

            idx = (idx + 1) % n;

        } 

        if(r_count == 0) return "Dire";
        return "Radiant";


    }
};