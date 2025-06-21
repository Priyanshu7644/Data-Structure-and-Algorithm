class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                temp[j]=nums[i];
                j++;
            }
        }
        if(j!=n){
            for(int i=j;j<n;j++){
                temp[j]=0;
            }
        }
        nums=temp;
    }
};