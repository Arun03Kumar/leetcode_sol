class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        // create a string for initial state, we know the target state
        // we can swap by nearby index to go to next state, and in one step we go to all near by states so we can say we are going level wise
        // for each index in the string we need to find the where we can go to the next step, so create a map for that
        // then simply do the BFS

        string start = "";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }

        string target = "123450";

        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        queue<string> q;
        q.push(start);

        unordered_set<string> visited;
        visited.insert(start);

        int level = 0;

        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                string front = q.front();
                q.pop();

                if(front == target) return level;

                int idx_of_zero = front.find("0");
                for(int &swap_idx: mp[idx_of_zero]) {
                    string temp = front;
                    swap(temp[swap_idx], temp[idx_of_zero]);

                    if(visited.find(temp) == visited.end()) {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }

            level++;
        }

        return -1;
    }
};