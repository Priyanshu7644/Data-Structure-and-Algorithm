class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int num:nums){
            if(find(ans.begin(),ans.end(),num)==ans.end()){
                ans.push_back(num);
            }
        }
        nums=ans;
        return ans.size();
    }
};