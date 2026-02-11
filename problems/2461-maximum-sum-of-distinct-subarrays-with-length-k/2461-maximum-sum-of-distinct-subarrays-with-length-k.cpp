class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long curr = 0;
        unordered_map<int,int>mp;

        for (int r = 0; r < n; r++) {
            
            curr += nums[r];
            mp[nums[r]]++;

            if (r >= k) {
                curr -= nums[r - k];
                mp[nums[r-k]]--;
                if(mp[nums[r-k]]==0){
                    mp.erase(nums[r-k]);
                }
            }

            if (r >= k - 1) {
                if(mp.size()==k){
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};