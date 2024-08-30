class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;

        for(string &s: emails) {
            string temp = "";
            int i = 0;
            bool is_after_at = false;
            while(i < s.size()) {
                if(s[i] == '@') is_after_at = true;
                if(!is_after_at && (s[i] == '+' || s[i] == '.')) {
                    if(s[i] == '.'){
                        i++;
                        continue;
                    } 
                    else {
                       while(s[i] != '@') i++; 
                       temp += s[i];
                       is_after_at = true;
                    }
                }
                else {
                    temp += s[i];
                }
                i++;
            }
            cout << temp << endl;
            st.insert(temp);
        }

        return st.size();
    }
};