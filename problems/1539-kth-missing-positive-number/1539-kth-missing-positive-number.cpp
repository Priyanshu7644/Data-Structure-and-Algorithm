class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0;
        int j=1;
        while(k>0){
            if(i<arr.size()  && arr[i]==j ){
                i++;
                j++;
            }
            else{
                j++;
                k--;
            }

            if(k==0){
                return j-1;
            }
        }
        return j-1;
    }
};