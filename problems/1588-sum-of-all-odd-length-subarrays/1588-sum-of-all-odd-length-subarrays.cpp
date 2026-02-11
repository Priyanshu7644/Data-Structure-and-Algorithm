class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=i;j<n;j++){
                curr+=arr[j];
                int len=j-i+1;
                if(len%2==1){
                    ans+=curr;
                }
            }
        }
        return ans;
    }
};