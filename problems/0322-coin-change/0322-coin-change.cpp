class Solution {
public:
    vector<vector<int>> dp;

    int helper(int index, int amount, vector<int>& coins) {

        if (amount == 0)
            return 0;

        if (index == coins.size())
            return 1e9;

        if (dp[index][amount] != -1)
            return dp[index][amount];

        int not_pick = helper(index + 1, amount, coins);

        int pick = 1e9;
        if (coins[index] <= amount) {
            pick = 1 + helper(index, amount - coins[index], coins);
        }

        return dp[index][amount] = min(pick, not_pick);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        dp.assign(n, vector<int>(amount + 1, -1));

        int ans = helper(0, amount, coins);

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};