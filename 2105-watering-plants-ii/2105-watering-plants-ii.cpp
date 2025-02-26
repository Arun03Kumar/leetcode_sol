class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0, j = plants.size() - 1;
        int ans = 0;

        int temp1 = capacityA, temp2 = capacityB;

        while(i <= j) {

            if(i != j) {
                if(plants[i] <= temp1) {
                    temp1 -= plants[i];
                }
                else {
                    ans++;
                    temp1 = capacityA - plants[i];
                }

                if(plants[j] <= temp2) {
                    temp2 -= plants[j];
                }
                else {
                    ans++;
                    temp2 = capacityB - plants[j];
                }

                i++;
                j--;
            }
            else {
                if(temp1 < plants[i] && temp2 < plants[j]) ans++;
                i++;
            }
        }

        return ans;
    }
};