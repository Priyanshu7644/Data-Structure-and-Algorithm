class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        
        vector<vector<vector<long long>>> dp(
            zero + 1,
            vector<vector<long long>>(one + 1, vector<long long>(2, 0))
        );

        for (int i = 1; i <= min(zero, limit); i++)
            dp[i][0][0] = 1;

        for (int j = 1; j <= min(one, limit); j++)
            dp[0][j][1] = 1;

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {

                for (int k = 1; k <= limit && z >= k; k++) {
                    dp[z][o][0] = (dp[z][o][0] + dp[z-k][o][1]) % MOD;
                }

                for (int k = 1; k <= limit && o >= k; k++) {
                    dp[z][o][1] = (dp[z][o][1] + dp[z][o-k][0]) % MOD;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};