class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> st;
        for(vector<int> &v: obstacles) {
            st.insert({v[0], v[1]});
        }

        int x = 0, y = 0;
        // vector<int> north = {0, 1};
        // vector<int> east = {1, 0};
        // vector<int> south = {0, -1};
        // vector<int> west = {-1, 0};

        string dir = "north";

        map<string, vector<int>> mp;
        mp["north"] = {0, 1};
        mp["east"] = {1, 0};
        mp["south"] = {0, -1};
        mp["west"] = {-1, 0};
        
        int ans = 0;
        for(int &k: commands) {

            if(dir == "north" && k == -2) dir = "west";
            else if(dir == "north" && k == -1) dir = "east";
            else if(dir == "west" && k == -2) dir = "south";
            else if(dir == "west" && k == -1) dir = "north";
            else if(dir == "south" && k == -2) dir = "east";
            else if(dir == "south" && k == -1) dir = "west";
            else if(dir == "east" && k == -2) dir = "north";
            else if(dir == "east" && k == -1) dir = "south";
            else {
                while(k--) {
                    x += mp[dir][0];
                    y += mp[dir][1];
                    cout << x << " " << y << endl;
                    if(st.find({x, y}) != st.end()) {
                        x -= mp[dir][0];
                        y -= mp[dir][1];
                        cout << x << " " << y;
                        // ans = max(ans, (int)(x * x + y * y));
                        break;
                    }
                    ans = max(ans, (int)(x * x + y * y));
                    

                }
                cout << endl;
            }

        }

        return ans;
    }
};