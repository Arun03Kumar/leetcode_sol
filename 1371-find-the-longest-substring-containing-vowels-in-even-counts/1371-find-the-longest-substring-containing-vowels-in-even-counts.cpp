class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mp;
    
        // Initialize an array to track the count of each vowel
        vector<int> vowelCount(5, 0); // Count of 'a', 'e', 'i', 'o', 'u'

        string currentState = "00000";  // Initial state where all vowels have even counts
        mp[currentState] = -1;
        
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Update count for the vowel encountered
            if (s[i] == 'a')      vowelCount[0] = (vowelCount[0] + 1) % 2;
            else if (s[i] == 'e') vowelCount[1] = (vowelCount[1] + 1) % 2;
            else if (s[i] == 'i') vowelCount[2] = (vowelCount[2] + 1) % 2;
            else if (s[i] == 'o') vowelCount[3] = (vowelCount[3] + 1) % 2;
            else if (s[i] == 'u') vowelCount[4] = (vowelCount[4] + 1) % 2;

            // Create a string representing the current parity state of vowels
            currentState = "";
            for (int j = 0; j < 5; ++j) {
                currentState += to_string(vowelCount[j]);
            }

            // Check if we've seen this state before
            if (mp.find(currentState) != mp.end()) {
                // Calculate the length of the substring
                maxLength = max(maxLength, i - mp[currentState]);
            } else {
                // Store the first occurrence of this state
                mp[currentState] = i;
            }
        }

        return maxLength;
    }
};