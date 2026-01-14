class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        else{
            int digits = 0, tempX = x;
        while(tempX != 0) {
            tempX /= 10;
            digits++; 
        }
        long long int sum = 0;
        tempX = x;
        while(x != 0){
            sum += pow(10, --digits) * (x % 10);
            x /= 10;
        }
        if(sum == tempX){
            return true;
        }
        else {
            return false;
        }
        }
        
    }
};