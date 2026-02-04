class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==0){
                stk.push(-1);
            }

            if(s[i]=='('){
                stk.push(i);
            }
            else{
                stk.pop();
                int k=0;
                if(stk.empty()){
                    stk.push(i);
                }
                else{
                    k=(i-stk.top());
                    ans=max(k,ans);
                }
            }
        }
        return ans;
    }
};