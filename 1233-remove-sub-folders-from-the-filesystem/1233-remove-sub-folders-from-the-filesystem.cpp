class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Approach 1:

        // unordered_set<string> st(begin(folder), end(folder));
        // vector<string> ans;

        // for(string &s: folder) {
            
        //     string temp_s = s;
        //     bool flag = false;
        //     while(!s.empty()) {
        //         size_t pos_last_slash = s.find_last_of('/');
        //         s = s.substr(0, pos_last_slash);
        //         cout << s << " ";

        //         if(st.find(s) != st.end()) {
        //             flag = true;
        //             break;
        //         }
        //     }

        //     if(!flag) ans.push_back(temp_s);

        // }

        // return ans;


        // Approach 2: sorting
        // if we sort then we can find in the previous array of current element and check
        // but if stirng is like: a/b/ca, then what we can do we can if previous string of this is parent of this string instead of finding substring with function
        // when we sort we can guranteed that first string will never have any parent and this will always be present in the answer

        sort(begin(folder), end(folder));
        vector<string> ans;
        ans.push_back(folder[0]);

        for(int i = 1; i < folder.size(); i++) {

            string curr_folder = folder[i];
            string last_folder = ans.back();
            last_folder += '/';

            if(curr_folder.find(last_folder) != 0) {
                ans.push_back(curr_folder);
            }

        }

        return ans;
    }
};