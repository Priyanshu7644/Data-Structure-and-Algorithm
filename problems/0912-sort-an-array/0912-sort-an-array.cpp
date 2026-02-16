class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);

        for (int curr = 1; curr < n; curr *= 2) {

            for (int left = 0; left < n; left += 2 * curr) {

                int mid = min(left + curr - 1, n - 1);
                int right = min(left + 2 * curr - 1, n - 1);

                int i = left;
                int j = mid + 1;
                int k = left;

                // merge
                while (i <= mid && j <= right) {
                    if (nums[i] <= nums[j])
                        temp[k++] = nums[i++];
                    else
                        temp[k++] = nums[j++];
                }

                while (i <= mid) temp[k++] = nums[i++];
                while (j <= right) temp[k++] = nums[j++];
            }

            // copy entire temp back safely
            nums = temp;
        }

        return nums;
    }
};