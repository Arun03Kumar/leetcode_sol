class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // so we need to maintian two maps one store the forward mapping and one stores the backward mapping because it may possible that there is a case where two characters are mapping to same element.
        
        unordered_map<char, char> forward_mapping, reverse_mapping;

        for(int i = 0; i < s.size(); i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if(forward_mapping.find(ch1) != forward_mapping.end() && forward_mapping[ch1] != ch2 || reverse_mapping.find(ch2) != reverse_mapping.end() && reverse_mapping[ch2] != ch1) {
                return false;
            }

            forward_mapping[ch1] = ch2;
            reverse_mapping[ch2] = ch1;
        }

        return true;
    }
};