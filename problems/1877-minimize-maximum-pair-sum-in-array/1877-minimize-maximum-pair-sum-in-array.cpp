class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int min_val = INT_MAX, max_val = INT_MIN;
        for (int num : nums) {
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }

        // Frequency array to simulate a sorted structure
        vector<int> freq(max_val + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }

        int left = min_val, right = max_val;
        int max_sum = 0;

        while (left <= right) {
            if (freq[left] == 0) {
                left++;
            } else if (freq[right] == 0) {
                right--;
            } else {
                max_sum = max(max_sum, left + right);
                freq[left]--;
                freq[right]--;
            }
        }

        return max_sum;
    }
};