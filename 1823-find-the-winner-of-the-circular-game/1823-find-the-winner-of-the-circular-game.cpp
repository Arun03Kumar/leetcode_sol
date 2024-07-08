class Solution {
public:
    int findTheWinner(int n, int k) {
        // Approach 1: O(n^2)
        // vector<int> arr;
        // for(int i = 1; i <= n; i++) {
        //     arr.push_back(i);
        // }

        // int i = 0;
        // while(arr.size() > 1) { //O(n)
        //     int idx = (i + k - 1) % arr.size();

        //     arr.erase(arr.begin() + idx); // O(n) because of shifting

        //     i = idx;
        // }
        // return arr[0];

        // Approach 2: using queue O(n.k)
        // add all elements into queue then pop k-1 elements and push them into the back of queue then remove the first element because that will now be the kth element which we want to remove

        queue<int> q;
        for(int i = 1; i <= n; i++) {
            q.push(i);
        }

        while(q.size() > 1) {
            for(int count = 1; count <= k - 1; count++) {
                q.push(q.front()); // push back the k-1 elements to the q
                q.pop();
            }
            q.pop(); // remove the kth element
        }
        return q.front();

    }
};