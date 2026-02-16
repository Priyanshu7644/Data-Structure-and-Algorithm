class Solution {
public:
    int helper(int x) {
        if (x == 0) return 0;
        if (x == 1) return -1;
        if (x == 2) return -2;
        if (x == 3) return -6;

        return -x*(x-1)/(x-2) + (x-3) + helper(x-4);
    }

    int clumsy(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;

        return n*(n-1)/(n-2) + (n-3) + helper(n-4);
    }
};