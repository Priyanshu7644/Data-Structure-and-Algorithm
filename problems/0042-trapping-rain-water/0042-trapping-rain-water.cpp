//PREFIX SUM-------

class Solution {
public:
    int trap(vector<int>& H) {
        int n = H.size();
        if (n == 0) return 0;

        vector<int> prefix(n), suffix(n);

        int mx = 0;

        // prefix max
        for (int i = 0; i < n; i++) {
            mx = max(mx, H[i]);
            prefix[i] = mx;
        }

        mx = 0;

        // suffix max
        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, H[i]);
            suffix[i] = mx;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += min(prefix[i], suffix[i]) - H[i];
        }

        return ans;
    }
};