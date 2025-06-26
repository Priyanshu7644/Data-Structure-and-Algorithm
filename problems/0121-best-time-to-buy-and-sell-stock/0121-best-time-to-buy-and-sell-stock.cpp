class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int min=INT_MAX;
        int diff=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];
            }
            diff=prices[i]-min;
            if(diff>profit){
                profit=diff;
            }
        }
        return profit;
    }
};