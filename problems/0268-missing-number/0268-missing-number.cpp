class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        
        for (int i = 0; i <= n; i++) {
            sum += i;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result += nums[i]; 
        }

        return sum - result;
    }
};