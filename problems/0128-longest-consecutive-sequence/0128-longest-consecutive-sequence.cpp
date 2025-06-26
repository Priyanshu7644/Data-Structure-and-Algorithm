class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen=1;
        int count=1;

        if(nums.empty()){
            return 0;
        }

        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            
            if(nums[i]==nums[i-1]){
                continue;
            }
            else if(nums[i]==nums[i-1]+1){
                count++;
            }
            else{
                if(count>maxlen){
                    maxlen=count;
                }
                count=1;
            }
        }
        return max(maxlen,count);
    }
};