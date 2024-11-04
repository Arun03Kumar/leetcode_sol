class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int median1 = (n + m) / 2 - 1;
        int median2 = (n + m) / 2;

        int med1_el = -1;
        int med2_el = -1;

        int i = 0, j = 0, k = 0;
        while(i < n && j < m) {

            if(nums1[i] <= nums2[j]) {
                
                if(k == median1) {
                    med1_el = nums1[i];
                }
                if(k == median2) {
                    med2_el = nums1[i];
                }

                k++;
                i++;

            }
            else {

                if(k == median1) {
                    med1_el = nums2[j];
                }
                if(k == median2) {
                    med2_el = nums2[j];
                }

                k++;
                j++;

            }
            // else {
            //     if(k == median1) {
            //         med1_el = nums2[j];
            //     }
            //     if(k == median2) {
            //         med2_el = nums2[j];
            //     }

            //     k++;
            //     j++;
            //     i++;
            // }

        }

        while(i < n) {
            if(k == median1) {
                med1_el = nums1[i];
            }
            if(k == median2) {
                med2_el = nums1[i];
            }

            k++;
            i++;
        }

        while(j < m) {
            if(k == median1) {
                med1_el = nums2[j];
            }
            if(k == median2) {
                med2_el = nums2[j];
            }

            k++;
            j++;
        }

        if((m + n) % 2 != 0) {
            return med2_el * 1.0;
        }
        else {
            return (med1_el + med2_el) / 2.0;
        }
    }

};