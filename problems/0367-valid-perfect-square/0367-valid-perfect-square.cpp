class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 0, high = num;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid >= num)
                high = mid;
            else
                low = mid + 1;
        }

        return low * low == num;
    }
};