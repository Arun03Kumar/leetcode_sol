class Solution {
public:
    const int M = 1e9 + 7;
    const int ALPHABET_SIZE = 26;

    // Matrix multiplication function with modulo
    vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int n = A.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j] % M) % M;
                }
            }
        }
        return result;
    }

    // Matrix exponentiation function
    vector<vector<long long>> matrixPower(vector<vector<long long>> base, long long exp) {
        int n = base.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));

        // Initialize result as the identity matrix
        for (int i = 0; i < n; ++i) result[i][i] = 1;

        while (exp > 0) {
            if (exp % 2 == 1) result = matrixMultiply(result, base);
            base = matrixMultiply(base, base);
            exp /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> initialFreq(ALPHABET_SIZE, 0);

        // Count initial frequency of each character in s
        for (char ch : s) initialFreq[ch - 'a']++;

        // Build the transition matrix
        vector<vector<long long>> transition(ALPHABET_SIZE, vector<long long>(ALPHABET_SIZE, 0));
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            int steps = nums[i];
            for (int j = 1; j <= steps; ++j) {
                int nextChar = (i + j) % ALPHABET_SIZE;
                transition[i][nextChar] = (transition[i][nextChar] + 1) % M;
            }
        }

        // Compute transition matrix raised to the power t
        vector<vector<long long>> poweredTransition = matrixPower(transition, t);

        // Calculate final frequencies after t transformations
        long long finalLength = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            long long sum = 0;
            for (int j = 0; j < ALPHABET_SIZE; ++j) {
                sum = (sum + poweredTransition[j][i] * initialFreq[j] % M) % M;
            }
            finalLength = (finalLength + sum) % M;
        }

        return finalLength;
    }
};
