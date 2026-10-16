class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        nums.clear();
        int count=0;
        int i=0;
        int m=mp.size();
        for(auto it:mp){
            if(it.second>2){
                count+=2;
                nums.push_back(it.first);
                nums.push_back(it.first);
            }
            else{
                count+=it.second;
                for(int i=0;i<it.second;i++){
                    nums.push_back(it.first);
                }
            }
        }
        sort(nums.begin(),nums.end());

        return count;
    }
};