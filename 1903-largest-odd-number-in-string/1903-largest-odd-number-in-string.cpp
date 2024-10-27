class Solution {
public:
    string largestOddNumber(string num) {
        unordered_set<char> st;
        st.insert('1');
        st.insert('3');
        st.insert('5');
        st.insert('7');
        st.insert('9');

        int n = num.size();
        string temp = num;
        for(int i = n - 1; i >= 0; i--) {
            if(st.find(temp[i]) != st.end()) return temp;

            temp.pop_back();
        }

        return "";
    }
};