#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // DP state: dp[rem_k][i][j] is the min cost to reach (i, j) with rem_k teleports used
        // Using long long for DP to prevent overflow, initialized to infinity
        const long long INF = 1e18;
        vector<vector<vector<long long>>> dp(k + 1, vector<vector<long long>>(m, vector<long long>(n, INF)));
        
        // Base case
        dp[0][0][0] = 0;
        
        for (int p = 0; p <= k; ++p) {
            // 1. Process Normal Moves (Down/Right) for the current teleport count 'p'
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[p][i][j] == INF) continue;
                    if (i + 1 < m) {
                        dp[p][i + 1][j] = min(dp[p][i + 1][j], dp[p][i][j] + grid[i + 1][j]);
                    }
                    if (j + 1 < n) {
                        dp[p][i][j + 1] = min(dp[p][i][j + 1], dp[p][i][j] + grid[i][j + 1]);
                    }
                }
            }
            
            // 2. Process Teleportation to increment to 'p + 1'
            if (p < k) {
                // Find the global minimum cost reached so far for each grid value
                // Since cost is 0 if grid[dest] <= grid[src], we only care about 
                // the min cost to reach ANY cell that has a grid value >= X.
                
                // Sort cell values to efficiently find the best teleport source
                vector<pair<int, long long>> sources;
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (dp[p][i][j] != INF) {
                            sources.push_back({grid[i][j], dp[p][i][j]});
                        }
                    }
                }
                
                if (sources.empty()) continue;
                
                sort(sources.begin(), sources.end());
                
                // Suffix minimum: min_cost[v] = min cost to reach any cell with grid value >= v
                // Because if we can reach a cell with value 100 with cost C, 
                // we can teleport to any cell with value <= 100 with cost C.
                for (int i = (int)sources.size() - 2; i >= 0; --i) {
                    sources[i].second = min(sources[i].second, sources[i + 1].second);
                }
                
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        // Binary search for the first source where source.grid_value >= grid[i][j]
                        auto it = lower_bound(sources.begin(), sources.end(), make_pair(grid[i][j], -1LL));
                        if (it != sources.end()) {
                            dp[p + 1][i][j] = min(dp[p + 1][i][j], it->second);
                        }
                    }
                }
            }
        }
        
        long long ans = INF;
        for (int p = 0; p <= k; ++p) {
            ans = min(ans, dp[p][m - 1][n - 1]);
        }
        
        return (int)ans;
    }
};