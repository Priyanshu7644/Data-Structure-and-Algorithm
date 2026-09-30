class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int orignal=x;

        while(x!=0){
            int temp=x%10;
            x=x/10;

            if(ans>INT_MAX/10) return 0;
            if(ans<INT_MIN/10) return 0;

            ans=ans*10+temp;
        }

        return ans;
    }
};