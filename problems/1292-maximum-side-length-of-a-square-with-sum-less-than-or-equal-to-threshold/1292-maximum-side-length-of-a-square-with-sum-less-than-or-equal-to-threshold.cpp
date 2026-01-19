class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        // Prefix sum array
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pre[i + 1][j + 1] = mat[i][j]
                    + pre[i][j + 1]
                    + pre[i + 1][j]
                    - pre[i][j];
            }
        }

        // Function to check if any square of side k is valid
        auto can = [&](int k) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int sum = pre[i + k][j + k]
                            - pre[i][j + k]
                            - pre[i + k][j]
                            + pre[i][j];
                    if (sum <= threshold)
                        return true;
                }
            }
            return false;
        };

        // Binary search on side length
        int left = 0, right = min(m, n);
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (can(mid))
                left = mid;
            else
                right = mid - 1;
        }

        return left;
    }
};