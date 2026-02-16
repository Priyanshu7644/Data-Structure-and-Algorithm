// class Solution {
// public:
//     int trailingZeroes(int n) {
//         long long fact = 1;

//         // compute factorial
//         for(int i = 1; i <= n; i++) {
//             fact *= i;
//         }

//         // count trailing zeros
//         int count = 0;
//         while(fact % 10 == 0) {
//             count++;
//             fact /= 10;
//         }

//         return count;
//     }
// };


class Solution {
public:
    int trailingZeroes(int n) {
        // base case
        if(n == 0) return 0;

        // count multiples of 5 recursively
        return n/5 + trailingZeroes(n/5);
    }
};