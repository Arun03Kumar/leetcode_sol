class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Approach 1: Greedy (Without heap)
        // first sort the task based on the frequency
        // create the idle holes after distributing all the tasks for highest freq char
        // ex. if A=4 and n = 2 then A _ _ A _ _ A _ _ A, so total holes is 3 not six
        //now fill the other elements inside the holes if the frequency of them is less than holes then it can be accomodated inside the holes
        // if not then accomodate the min of freq and holes -> min(freq, holes) and subtract the frequency of that character
        // when holes == 0 it means it can accomodate all characters and answer will be equal to the number of freq of all chars
        // if freq of all elements are 0 but holes are still remaining then it means ans will be freq of all + number of remaining holes

        vector<int> freq(26, 0);
        for(char &ch: tasks) freq[ch - 'A']++;

        sort(begin(freq), end(freq));

        int max_freq = freq[25];
        int holes = max_freq - 1;
        int idle_slots = n * holes;

        for(int i = 24; i >= 0; i--) {
            idle_slots -= min(freq[i], holes);
        }

        if(idle_slots > 0) return tasks.size() + idle_slots;
        return tasks.size();
    }
};