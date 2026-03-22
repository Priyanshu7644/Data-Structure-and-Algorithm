class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>ans(n,0);
        int currDay=0;
        for(int temp: temperatures){
            while(!st.empty() && temp>temperatures[st.top()]){
                int prevDay=st.top();
                st.pop();
                ans[prevDay]=currDay-prevDay;
            }
            st.push(currDay);
            currDay++;
        }
        return ans;
    }
};