class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>smp,tmp;

        if (s.length() != t.length()) return false;

        for(int i=0;i<s.length();i++){
            if(smp.count(s[i])){
                if(smp[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
                smp[s[i]]=t[i];
            }

            if(tmp.count(t[i])){
                if(tmp[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
                tmp[t[i]]=s[i];
            }

        }
        return true;
    }
};