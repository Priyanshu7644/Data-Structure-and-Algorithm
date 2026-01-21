class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {
            // Even numbers are impossible
            if (n % 2 == 0) {
                ans.push_back(-1);
                continue;
            }

            // Count trailing 1s
            int k = 0;
            int temp = n;
            while (temp & 1) {
                k++;
                temp >>= 1;
            }

            // Subtract 2^(k-1)
            ans.push_back(n - (1 << (k - 1)));
        }

        return ans;
    }
};