class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i:nums){
            mp[i]++;
        }
        
        int max=0;
        for(auto it:mp){
            if(it.second>nums.size()/2){
                return it.first;
            }

            if(it.second>max){
                ans=it.first;
            }
        }
        return ans;
    }
};