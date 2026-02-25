class Solution {
public:
    long long gcd(long long a,long long b){
        while(b!=0){
            long long t=b;
            b=a%b;
            a=t;
        }
        return a;
    }

    long long lcm(long long a,long long b){
        return (a/gcd(a,b)*b);
    }
    
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            long long product=1;
            long long g=0;
            long long l=1;
            for(int j=i;j<n;j++){
                if(product>LLONG_MAX/nums[j]) break;
                product*=nums[j];
                if(g==0) g=nums[j];
                else g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);

                if(product==g*l){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};