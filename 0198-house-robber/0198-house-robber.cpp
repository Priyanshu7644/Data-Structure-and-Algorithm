class Solution {
public:

    int solve(vector<int>&nums,vector<int>&dp,int i){
        if(i>=nums.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        int pick=nums[i]+solve(nums,dp,i+2);
        int not_pick=solve(nums,dp,i+1);

        return dp[i]=max(pick,not_pick);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,dp,0);
    }
};