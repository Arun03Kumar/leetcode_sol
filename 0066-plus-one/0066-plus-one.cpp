class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        bool flag = false;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(i == digits.size() - 1) { 
                int sum = digits[i] + 1 + carry;
                digits[i] = sum % 10;
                carry = sum / 10;
                flag = true;
            } else {
                int sum = digits[i] + carry;
                digits[i] = sum % 10;
                carry = sum / 10;
                flag = true;
            }
            if(!flag) return digits;
        }
        if(carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};