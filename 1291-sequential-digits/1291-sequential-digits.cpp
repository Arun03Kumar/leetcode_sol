class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // for this type of questions try BFS appraoch
        // if last digit is 9 then we can not create any sequential digit
        // hence we can start with 1 to 8 and keep on creating the sequential digit 
        // if that falls under the range we will put it into ans
        // and if it is less than we will again push into queue
        // but if it is larger then we can not include it

        // 

        queue<int> q;
        for(int i = 1; i <= 8; i++) {
            q.push(i);
        }

        vector<int> ans;
        while(!q.empty()) {
            int num = q.front();
            q.pop();

            if(num >= low && num <= high) ans.push_back(num);

            int last_digit = num % 10;
            int new_num;
            if(last_digit + 1 <= 9) {
                new_num = num * 10 + (last_digit + 1);
            }
            else continue;

            if(new_num <= high) {
                q.push(new_num);
            }
        }

        return ans;
    }
};