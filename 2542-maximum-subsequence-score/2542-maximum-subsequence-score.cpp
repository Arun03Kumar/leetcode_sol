class Solution {
public:
    int K;
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

    void remove_from_pq(int num) {
        vector<int> temp;

        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();

            if(x == num) break;

            temp.push_back(x);
        }

        for(int &x: temp) pq.push(x);
    }

    int recursion(vector<int>& nums1, vector<int>& nums2, int sum, int min, int idx, int count) {
        if(count == K) return sum * min;

        if(idx >= n) return 0;

        // when we take any element then push the corresponding element from nums2 into the pq
        pq.push(nums2[idx]);
        int take_idx = recursion(nums1, nums2, sum + nums1[idx], pq.top(), idx + 1, count + 1);

        // when we are not taking the idx, in this case we have to first remove the taken element from the pq
        remove_from_pq(nums2[idx]);
        int not_take_idx = recursion(nums1, nums2, sum, min, idx + 1, count);

        return max(take_idx, not_take_idx);

    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // K = k;
        // n = nums1.size();
        // Approach 1: recursion
        // sum stores the sum of taken elements, min stores the min element in taken from nums2, idx tells the index of current, count tells how many elements we have taken in the subsequence
        // return recursion(nums1, nums2, 0, 0, 0, 0);



        // Approach 2: greedy with priority queue
        // since we want to maximize the score, so we can try to find the maximum element from nums2 and then create subsequence according to it
        // so sort the nums2 in decreasing ordere, but if we sort nums2 we also want to have the correspondances hence create a vector of pair
        // but if k > 1 then we can not choose the first element as the minimum because that would be maximum in nums2 and then if we choose anothe k-1 elements then definitly those will be minimum
        // hence we have to choose the first minimum element from idx k - 1;
        // so take k-1 elements from nums1 and add them, then multiply with the k-1 th element from nums2
        // so sum will contain the k elements put these k elements in to a min heap
        // so that we could play optimally and remove the min element because we want to maximize the score
        // so when we add the next element then remove the min element from the sum and add the next element in the sum as well as in the min heap

        int n = nums1.size();
        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++) {
            vec.push_back({nums1[i], nums2[i]});
        }

        auto comp = [&](auto x1, auto x2) {
            return x1.second > x2.second;
        };
        sort(begin(vec), end(vec), comp);

        priority_queue<int, vector<int>, greater<int>> pq;

        long long k_sum = 0;

        for(int i = 0; i < k; i++) {
            k_sum += vec[i].first;
            pq.push(vec[i].first);
        }

        long long ans = k_sum * vec[k - 1].second;

        for(int i = k; i < n; i++) {
            int min_el = pq.top();
            pq.pop();

            k_sum = k_sum - min_el + vec[i].first;
            pq.push(vec[i].first);

            long long temp = k_sum * vec[i].second;
            ans = max(ans, temp);

        }

        return ans;
    }
};