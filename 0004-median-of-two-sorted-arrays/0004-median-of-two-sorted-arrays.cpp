class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Approach 1: using Merge algorithm
        // int n = nums1.size();
        // int m = nums2.size();

        // int median1 = (n + m) / 2 - 1;
        // int median2 = (n + m) / 2;

        // int med1_el = -1;
        // int med2_el = -1;

        // int i = 0, j = 0, k = 0;
        // while(i < n && j < m) {

        //     if(nums1[i] <= nums2[j]) {
                
        //         if(k == median1) {
        //             med1_el = nums1[i];
        //         }
        //         if(k == median2) {
        //             med2_el = nums1[i];
        //         }

        //         k++;
        //         i++;

        //     }
        //     else {

        //         if(k == median1) {
        //             med1_el = nums2[j];
        //         }
        //         if(k == median2) {
        //             med2_el = nums2[j];
        //         }

        //         k++;
        //         j++;

        //     }
        // }

        // while(i < n) {
        //     if(k == median1) {
        //         med1_el = nums1[i];
        //     }
        //     if(k == median2) {
        //         med2_el = nums1[i];
        //     }

        //     k++;
        //     i++;
        // }

        // while(j < m) {
        //     if(k == median1) {
        //         med1_el = nums2[j];
        //     }
        //     if(k == median2) {
        //         med2_el = nums2[j];
        //     }

        //     k++;
        //     j++;
        // }

        // if((m + n) % 2 != 0) {
        //     return med2_el * 1.0;
        // }
        // else {
        //     return (med1_el + med2_el) / 2.0;
        // }

        // Approach 2: Using Binary Search
        // if we combine two arrays then total elements would be (n+m), 
        // so basically we make two partitions left and right, and we try to put elements from both arrays into the left half and right half of the combined array
        // if we have 3 + 4 elements in num1, num2 respectively 
        // and in combined total will be 7, we partition 4 in left and 3 in right
        //and if we choose  2 elements from num1 then 2 should be choosen from num2
        // and remaining will go into right partition
        // but we need to check if that partitioning is correct or not
        // we can do that by checking if largest element from left partion and from num1 array is greater than the smallest from right and num2 then this is not correct partitioning
        // also if largest from left and num2 is greater than the smallest in num1 and right then also it is invalid
        // num1 - [1,3,8]     num2 - [7,9,10,11]
        // now total is 7 and left will contain 4 elements and right partition will contain 3 elements
        // let we choose 2 from num1 to put in to left
        //     1,3 | 8
        //     7,9 | 10, 11 
        // this will be the configuration at that time
        // in left we have 1,3 from num1 and 7,9 from num2
        // we can see that largest of num1 from left (3) is smaller than smallest of num2 from right (10), which is valid
        // but largest of num2 from left is greater than smallest of num1 from right, which is invalid
        // main key is that in left we should always have smaller elements than right one, because that would make the array sorted right

        int n = nums1.size();
        int m = nums2.size();

        // this way we are ensuring that num1 is always smaller array
        if(n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0, r = n;
        int total = n + m;

        while(l <= r) {

            int mid = l + (r - l) / 2;
            int idx_nums2 = (total + 1) / 2 - mid; // we did total + 1 because that will automatically handle if m+n is even or odd

            // it may possible that we took all elements in the right array of nums 1 then in that case we have to choose small or large number 
            int num1_largest_left = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int num1_smallest_right = (mid == n) ? INT_MAX : nums1[mid];

            int num2_largest_left = (idx_nums2 == 0) ? INT_MIN : nums2[idx_nums2 - 1];
            int num2_smallest_right = (idx_nums2 == m) ? INT_MAX : nums2[idx_nums2];

            if(num1_largest_left <= num2_smallest_right && num2_largest_left <= num1_smallest_right) {

                // this is the valid case now calculate median
                if(total % 2 == 0) {
                    int lar_left = max(num1_largest_left, num2_largest_left);
                    int smal_rig = min(num1_smallest_right, num2_smallest_right);
                    return (lar_left + smal_rig) / 2.0;
                }
                else {
                    return max(num1_largest_left, num2_largest_left) * 1.0;
                }

            }

            if(num1_largest_left > num2_smallest_right) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }

        }

        return -1;
    }

};