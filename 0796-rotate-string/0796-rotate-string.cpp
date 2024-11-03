class Solution {
public:
    bool rotateString(string s, string goal) {
        // Approach 1:

        // int n = s.size();
        // while(n--) {
        //     char c = s[0];
        //     s.erase(0, 1);
        //     s.push_back(c);
        //     cout << s << " ";
        //     if(s == goal) return true;
        // }

        // return false;


        // Approach 2: using rotate function
        // the args in rotate fn are like this
        // rotate(start ptr, position which will become the start, end ptr)
        // int n = s.size();
        // for(int i = 0; i < n; i++) {
        //     rotate(begin(s), begin(s) + 1, end(s));

        //     if(s == goal) return true;
        // }
        // return false;

        
        // Approach 3:
        // if we concatanate the string in itself then it will contains all the rotations in at as a substring
        s = s + s;
        if(s.find(goal) != string::npos) return true;

        return false;
    }
};