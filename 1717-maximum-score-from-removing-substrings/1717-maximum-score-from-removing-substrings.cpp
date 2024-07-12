class Solution {
public:
    string remove_substr(string s, string &sub_str) {
        stack<char> st;

        for(char ch: s) {
            if(ch == sub_str[1] && !st.empty() && st.top() == sub_str[0]) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        string tmp;
        while(!st.empty()) {
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }

    string remove_substr_two_pointer(string &s, string &sub_str) {
        // maintain two pointer i & j, j will always move ahead and assign the character at jth index to the ith index, increase the pointer then check previous two values of i if they match to substr if they match then decrement i by 2;
        //at last remove the character after ith index.
        int i = 0;
        for(int j = 0; j < s.size(); j++) {
            s[i] = s[j];
            i++;

            if(i >= 2 && s[i - 2] == sub_str[0] && s[i - 1] == sub_str[1]) {
                i -= 2;
            }
        }
        s.erase(s.begin() + i, s.end());
        return s;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.length(), ans = 0;
        string max_str = x > y ? "ab" : "ba";
        string min_str = x < y ? "ab" : "ba";

        // string temp_first = remove_substr_with_stack(s, max_str);
        string temp_first = remove_substr_two_pointer(s, max_str);
        int tmp_first_size = temp_first.length();

        int char_removed = n - tmp_first_size;
        ans += ((char_removed / 2) * max(x, y));

        // string temp_second = remove_substr_with_stack(temp_first, min_str);
        string temp_second = remove_substr_two_pointer(temp_first, min_str);
        int temp_second_size = temp_second.length();

        char_removed = tmp_first_size - temp_second_size;
        ans += ((char_removed / 2) * min(x, y));

        return ans;
    }
};