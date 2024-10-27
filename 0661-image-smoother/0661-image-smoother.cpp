class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();

        vector<vector<int>> ans(rows, vector<int>(cols));
        vector<vector<int>> dir = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                int temp = img[i][j];
                int count = 1;
                for(vector<int> &v: dir) {

                    int new_i = i + v[0];
                    int new_j = j + v[1];

                    if(new_i < 0 || new_j < 0 || new_i >= rows || new_j >= cols) {
                        continue;
                    }
                    else {
                        temp += img[new_i][new_j];
                        count++;
                    }

                }
                cout << temp << " " << count << endl;
                ans[i][j] = temp / count;

            }
        }

        return ans;
    }
};