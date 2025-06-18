class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, write_ptr = 0, n = chars.size();
        int count = 0;

        while(i < n) {
            char curr_ch = chars[i];
            while(i < n && chars[i] == curr_ch) {
                i++;
                count++;
            }

            chars[write_ptr++] = curr_ch;
            if(count > 1) {
                string num = to_string(count);
                for(char ch: num) {
                    chars[write_ptr++] = ch;
                }
            }

            count = 0;
        }

        return write_ptr;
    }
};