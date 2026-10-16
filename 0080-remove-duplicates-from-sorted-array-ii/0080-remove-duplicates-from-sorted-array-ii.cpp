class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        int count=0;
        int i=0;
        int m=mp.size();
        vector<int>ans;
        for(auto it:mp){
            if(it.second>2){
                count+=2;
                ans.push_back(it.first);
                ans.push_back(it.first);
            }
            else{
                count+=it.second;
                for(int i=0;i<it.second;i++){
                    ans.push_back(it.first);
                }
            }
        }
        sort(ans.begin(),ans.end());
        nums=ans;

        return count;
    }
};