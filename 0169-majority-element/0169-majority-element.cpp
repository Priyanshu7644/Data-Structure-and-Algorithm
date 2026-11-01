class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }

        int size=nums.size();
        for(auto it:mp){
            if(it.second>size/2){
                return it.first;
            }
        }
        return 0;
    }
};