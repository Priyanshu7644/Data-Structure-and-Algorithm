class Solution {
public:
    void getsubsets(vector<int>& nums,vector<int>&ans,int i,vector<vector<int>>&allSubsets) {
        if(i==nums.size()){
            allSubsets.push_back(ans);
            return;
        }

        //include
        ans.push_back(nums[i]);
        getsubsets(nums,ans,i+1,allSubsets);

        //backtracking
        ans.pop_back();

        //exclude
        getsubsets(nums,ans,i+1,allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allSubsets;
        getsubsets(nums,ans,0,allSubsets);
        return allSubsets;
    }
};