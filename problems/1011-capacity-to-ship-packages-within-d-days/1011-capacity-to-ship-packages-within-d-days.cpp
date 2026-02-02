class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;

        for (int w : weights) {
            low = max(low, w);   
            high += w;          
        }

        while (low < high) {
            int mid = low + (high - low) / 2;

            int neededDays = 1;
            int current = 0;

            for (int w : weights) {
                if (current + w > mid) {
                    neededDays++;
                    current = 0;
                }
                current += w;
            }

            if (neededDays <= days)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};