class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        
        int left=low;
        if(low==n || nums[left]!=target  ){
            return {-1,-1};
        }
        
        low=0,high=n;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        int right=low-1;
        
        return {left,right};
    }
};