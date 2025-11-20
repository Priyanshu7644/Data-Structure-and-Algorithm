class Solution {
public:
    void getSubsetsWithDup(vector<int>&nums,vector<int>&ans,int i,vector<vector<int>>&final){
        if(i==nums.size()){
            final.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        getSubsetsWithDup(nums,ans,i+1,final);

        ans.pop_back();

        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        getSubsetsWithDup(nums,ans,i+1,final);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<vector<int>>final;
        getSubsetsWithDup(nums,ans,0,final);
        return final;
    }
};