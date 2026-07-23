//MEMORIZATION:-
class Solution {
public:
    vector<vector<int>>dp;
    int helper(int index,int amount,vector<int>&coins){
        if(amount==0){
            return 1;
        }
        if(index==coins.size()){
            return 0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int not_pick= helper(index + 1, amount, coins);

        int pick = 0;
        if (coins[index] <= amount) {
            pick = helper(index, amount - coins[index], coins);
        }

        return dp[index][amount] = pick + not_pick;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return helper(0,amount,coins);
    }
};