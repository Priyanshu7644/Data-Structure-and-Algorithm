class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        for(char x:s){
            if(mp.count(x)){
                if (st.empty()) {
                    return false;
                }
                if(st.top()==mp[x]){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
            st.push(x);
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};