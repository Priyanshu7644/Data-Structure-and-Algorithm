class Solution {
public:

    bool subsetSum(vector<int>& nums, int target){
        int n = nums.size();
        bool dp[n+1][target+1];

        for(int i=0;i<=n;i++)
            dp[i][0] = true;

        for(int j=1;j<=target;j++)
            dp[0][j] = false;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){

                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];

            }
        }

        return dp[n][target];
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for(int x : nums)
            sum += x;

        if(sum % 2 != 0)
            return false;

        return subsetSum(nums, sum/2);
    }
};