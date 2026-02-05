class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
    int n=arr.size();
    stack<int>stk;
    vector<int>nse(n),pse(n);
    
    //NSE
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && arr[stk.top()]>=arr[i]){
            stk.pop();
        }

        if(stk.empty()) nse[i]=n;
        else nse[i]=stk.top();
        stk.push(i);
    }
    //clear stack
    while (!stk.empty()) stk.pop();

    //PSE
    for(int  i=0;i<n;i++){
        while(!stk.empty() && arr[stk.top()]>=arr[i]){
            stk.pop();
        }
        if(stk.empty()) pse[i]=-1;
        else pse[i]=stk.top();
        stk.push(i);
    }
    int width=0;
    int ans=0;
    for(int i=0;i<n;i++){
        width=nse[i]-pse[i]-1;
        ans=max(ans,width*arr[i]);
    }
    
    return ans;

    }
};