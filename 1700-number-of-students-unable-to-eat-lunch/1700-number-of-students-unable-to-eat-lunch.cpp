class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Approach 1: simulation
        queue<int> q(students.begin(), students.end());
        reverse(sandwiches.begin(), sandwiches.end());
        stack<int> st(begin(sandwiches), end(sandwiches));

        int count = 0;
        while(!st.empty() && count <= q.size()) {

            if(q.front() == st.top()) {
                q.pop();
                st.pop();
                count = 0;
            }
            else {
                int front = q.front();
                q.pop();
                q.push(front);
                count++;
            }

        }

        return q.size();
    }
};