class Solution {
public:
    bool isPalindrome(int x) {
        long long ans=0;
        int orignal=x;
        if(x<0) return false;

        while(x>0){
            int temp=x%10;
            ans=ans*10+temp;
            x=x/10;
        }

        return orignal==ans;
    }
};