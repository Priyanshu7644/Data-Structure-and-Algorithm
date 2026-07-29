class Solution {
public:
    const long long LIMIT = 1000000;

    long long combCap(int n, int r, long long cap) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        long long res = 1;

        for (int i = 1; i <= r; i++) {
            long long num = n - r + i;
            long long den = i;

            long long g = gcd(num, den);
            num /= g;
            den /= g;

            g = gcd(res, den);
            res /= g;
            den /= g;

            __int128 cur = (__int128)res * num;
            cur /= den;

            if (cur > cap) return cap;

            res = (long long)cur;
        }

        return res;
    }

    long long countWays(vector<int> &cnt) {
        long long ways = 1;
        int rem = 0;

        for (int c : cnt) {
            if (c == 0) continue;

            rem += c;

            ways = min(LIMIT, ways * combCap(rem, c, LIMIT));

            if (ways >= LIMIT) return LIMIT;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid = char('a' + i);
        }

        if (countWays(half) < k)
            return "";

        int len = s.size() / 2;
        string left = "";

        for (int pos = 0; pos < len; pos++) {

            for (int ch = 0; ch < 26; ch++) {

                if (half[ch] == 0) continue;

                half[ch]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + ch));
                    break;
                } else {
                    k -= ways;
                    half[ch]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;

        return left + right;
    }
};