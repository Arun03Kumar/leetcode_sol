class Solution {
public:

    // 1. we are using unordered_map<string, int> to store the elements;
    // 2. before starting we should push an empty map in the stack.
    // 3. when we encounter opeaning bracket it means we need to first process the inner elements in seperate map, hence we create another map and push it to the stack and process those elements seperately.
    //4. when we encounter a closing bracket it means we processes inner element now its time to merge them into other elements which were present outsie the brackets.
    // 

    string countOfAtoms(string formula) {
        stack<unordered_map<string, int> > st;
        st.push(unordered_map<string, int>());

        int i = 0;
        while(i < formula.size()) {

            if(formula[i] == '(') {

                st.push(unordered_map<string, int>());
                i++;

            }
            else if(formula[i] == ')') {

                unordered_map<string, int> top_map = st.top();
                st.pop();

                i++;

                // in this we are checking the number after the closing bracket
                string multiplier;
                while(i < formula.size() && isdigit(formula[i])) {

                    multiplier += formula[i];
                    i++;

                }

                // if it is not empty then it means we have to multiply it with all the elements in the top of map
                if(!multiplier.empty()) {

                    int int_multiplier = stoi(multiplier);
                    for(auto x: top_map) {

                        string el = x.first;
                        int count = x.second;
                        top_map[el] = count * int_multiplier;

                    }

                }

                // since we pop the top elements so we have to add them into next top elements.
                for(auto [el, count]: top_map) {
                    st.top()[el] += count;
                }

            }
            else {

                // in this section we are processing the atom name strings
                string curr_atom;
                curr_atom += formula[i];

                i++;

                // checking if character is lowercase it means it has name likr Hg, He
                while(i < formula.size() && islower(formula[i])) {

                    curr_atom += formula[i];
                    i++;

                }

                // after the name we are checking the count
                string curr_count;
                while(i < formula.size() && isdigit(formula[i])) {

                    curr_count += formula[i];
                    i++;

                }

                int count = curr_count.empty() ? 1 : stoi(curr_count);
                st.top()[curr_atom] += count;
                
            }

        }

        map<string, int> sorted_map(st.top().begin(), st.top().end());

        string ans;

        for(auto [atom, count]: sorted_map) {
            ans += atom;
            if(count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};