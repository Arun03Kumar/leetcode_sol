class Solution {
public:
    string convertToTitle(int columnNumber) {
        // it is basically how decimal system or any other system works
        // eg. 1,2,3,4,5...9,10,11,12... after 10 digits it changes so after base digits number repeats itself
        // same thing we have to do it here we just have to find the multiple of 26 and replace it with the mapped character
        // we can easily find the mapping since if we add any number to the character A, it will give that ascii number in that position
        // char ch = rem - 1 + 'A'; -> this will give @ for rem = 0, because 0 - 1 + 'A' == 64
        // hence what we can do we can 
        string ans = "";
        while(columnNumber > 0) {

            // By decrementing at the start, we’re telling the code: "Think of 1 as 0, 2 as 1, etc.
            columnNumber--;

            int rem = columnNumber % 26;
            columnNumber /= 26;

            // char ch = rem - 1 + 'A';
            char ch = rem + 'A';
            ans.push_back(ch);
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};