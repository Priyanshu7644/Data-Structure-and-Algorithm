class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a=nums[0];
        int b=nums[0];
        for(int num:nums){
            if(num<a){
                a=num;
            }
            if(num>b){
                b=num;
            }
        }

        int ans=1;
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }

        return a;
    }
};