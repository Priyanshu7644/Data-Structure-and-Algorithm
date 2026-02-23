class Solution {
public:
    map<int,int>memo;
    int fib(int n) {
        if(n<=1) return n;
        if(memo.find(n)!=memo.end()) return memo[n];
        return memo[n]=fib(n-1)+fib(n-2);
    }
};