class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            if(piles[i]>max){
                max=piles[i];
            }
        }
        int low=1,high=max;
        
        while(low<high){
            int mid=low+(high-low)/2;
            long long sum=0;
            for(auto it:piles){
                sum+=(it+mid-1)/mid;
            }

            if(sum<=h){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
    return low;
    }   
};