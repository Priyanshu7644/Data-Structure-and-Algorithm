class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;

        if (freq.count(1)) {
            int c = freq[1];
            ans = max(ans, (c % 2 == 0) ? c - 1 : c);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (freq.count(cur) && freq[cur] >= 2) {
                len += 2;
                cur = cur * cur;   
            }

            if (freq.count(cur) && freq[cur] >= 1) {
                ans = max(ans, len + 1);
            } else {
                ans = max(ans, len - 1);
            }
        }

        return ans;
    }
};