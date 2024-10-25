class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Approach 1:

        unordered_set<string> st(begin(folder), end(folder));
        vector<string> ans;

        for(string &s: folder) {
            
            string temp_s = s;
            bool flag = false;
            while(!s.empty()) {
                size_t pos_last_slash = s.find_last_of('/');
                s = s.substr(0, pos_last_slash);
                cout << s << " ";

                if(st.find(s) != st.end()) {
                    flag = true;
                    break;
                }
            }

            if(!flag) ans.push_back(temp_s);

        }

        return ans;
    }
};