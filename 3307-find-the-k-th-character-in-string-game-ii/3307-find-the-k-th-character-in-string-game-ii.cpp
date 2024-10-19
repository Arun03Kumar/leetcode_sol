class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // here we don't have to create the final string
        // since string is dependent on the previous string so we can find a recurrence relation with the previous string to find the character
        // also we need not start from the last string, we can start by that string which length is just greater than or equal to the k
        // if k is character we have to find then it will be the same character as k - len/2 th charater in previous string 
        // but value will be depend on the type of operation performed 

        if(k == 1) return 'a';

        int n = operations.size();
        long long len = 1;
        long long new_k = -1;
        int operation_type = -1;

        for(int i = 0; i < n; i++) {
            len *= 2;

            if(len >= k) {

                operation_type = operations[i];
                new_k = k - (len / 2);
                break;
            }
        }

        char ch = kthCharacter(new_k, operations);

        if(operation_type == 0) return ch;

        return ch == 'z' ? 'a' : ch + 1;

    }
};