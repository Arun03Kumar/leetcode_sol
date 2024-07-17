class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // it simple bfs on all possible combinations
        // if we are at 0000 then we are generating all combinations levle wise and push them into queue. ex. 0000 is converted to 1000, 9000 then second character 0100, 0900, then third index 0010, 0090 and so on then we generate for each character and check if it is present in the deadends.

        unordered_set<string> st(deadends.begin(), deadends.end());
        queue<string> q;

        string start = "0000";
        if(st.find(start) != st.end()) return -1;

        q.push(start);
        st.insert(start);

        int level = 0;

        while(!q.empty()) {
            int N = q.size();

            while(N--) {

                string front = q.front();
                q.pop();

                if(front == target) return level;

                for(int i = 0; i < 4; i++) {

                    char ch = front[i];

                    char decrease = ch == '0' ? '9' : ch - 1;
                    char increase = ch == '9' ? '0' : ch + 1;

                    front[i] = decrease;
                    if(st.find(front) == st.end()) {

                        q.push(front);
                        st.insert(front);

                    }

                    front[i] = increase;
                    if(st.find(front) == st.end()) {

                        q.push(front);
                        st.insert(front);

                    }

                    front[i] = ch;

                }

            }
            level++;
        }
        return -1;
    }
};