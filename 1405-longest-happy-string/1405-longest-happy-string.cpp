class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        // we need to use lower frequency characters as fillers so that we can accomodate more characters in the answer
        // if previous two characters from ans is same as top character in pq then we use othre top character
        // we build the answer by one character at a time
        priority_queue<P, vector<P>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string ans = "";
        while(!pq.empty()) {

            int curr_count = pq.top().first;
            char curr_char = pq.top().second;
            pq.pop();

            int size = ans.size();
            if(size >= 2 && ans[size - 1] == curr_char && ans[size - 2] == curr_char) {
                if(pq.empty()) break;

                int next_count = pq.top().first;
                char next_char = pq.top().second;
                pq.pop();

                ans.push_back(next_char);
                next_count--;

                if(next_count > 0) pq.push({next_count, next_char});

            }
            else {
                ans.push_back(curr_char);
                curr_count--;

            }

            if(curr_count > 0)pq.push({curr_count, curr_char});
        }

        return ans;
    }
};