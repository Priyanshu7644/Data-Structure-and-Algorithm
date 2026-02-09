class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //could have used set but TLE
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:nums){
            pq.push(x);
        }
        for(int i=0;i<n-k;i++){
            pq.pop();
        }

        return pq.top();
    }
};