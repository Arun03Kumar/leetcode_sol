class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;

        unordered_set<string> st;
        st.insert("0_0");

        for(char &ch: path) {
            if(ch == 'N') y++;
            else if(ch == 'S') y--;
            else if(ch == 'E') x++;
            else x--;

            string temp = to_string(x) + '_' + to_string(y);
            cout << temp << " ";
            if(st.find(temp) == st.end()) {
                st.insert(temp);
            }
            else return true;
        }

        return false;
    }
};