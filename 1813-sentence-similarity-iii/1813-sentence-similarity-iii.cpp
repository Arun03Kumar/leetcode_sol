class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // since we need to add somewhere in between then it means prefix means string from start should match 
        // strings from end should match
        // so we could take pointers to do this
        // if(sentence1.size() < sentence2.size()) {
        //     swap(sentence1, sentence2);
        // }

        // vector<string> sen1, sen2;

        // stringstream ss1(sentence1);
        // string token;

        // while(ss1 >> token) {
        //     sen1.push_back(token);
        // }

        // stringstream ss2(sentence2);
        // while(ss2 >> token) {
        //     sen2.push_back(token);
        // }

        // int i = 0, j = sen1.size() - 1;
        // int k = 0, l = sen2.size() - 1;

        // while(k < sen2.size() && i < sen1.size() && sen2[k] == sen1[i]) {
        //     k++;
        //     i++;
        // }

        // while(l >= k && sen2[l] == sen1[j]) {
        //     l--;
        //     j--;
        // }

        // return l < k;


        // Approach 2: Dequeue

        if(sentence1.size() < sentence2.size()) {
            swap(sentence1, sentence2);
        }

        deque<string> deq1, deq2;

        stringstream ss1(sentence1);
        string token;

        while(ss1 >> token) {
            deq1.push_back(token);
        }

        stringstream ss2(sentence2);
        while(ss2 >> token) {
            deq2.push_back(token);
        }

        while(!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front()) {
            deq1.pop_front();
            deq2.pop_front();
        }

        while(!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back()) {
            deq1.pop_back();
            deq2.pop_back();
        }

        return deq2.empty();

    }
};