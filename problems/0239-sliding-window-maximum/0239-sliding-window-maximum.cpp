class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            //remove indexes which are no longer in window
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            //always maintain increaing order
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);

            //push the valid ones in ans vector
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};