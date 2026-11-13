class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     int m = nums1.size();
    // int n = nums2.size();

    vector<int> merged(m + n);

    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            merged[k++] = nums1[i++];
            // i++;
        }
        else
        {
            merged[k++] = nums2[j++];
            // j++;
        }

        // k++;
    }

    while (i < m)
    {
        merged[k] = nums1[i];
        i++;
        k++;
    }

    while (j < n)
    {
        merged[k] = nums2[j];
        j++;
        k++;
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        nums1[i] = merged[i];
    }

    }
};