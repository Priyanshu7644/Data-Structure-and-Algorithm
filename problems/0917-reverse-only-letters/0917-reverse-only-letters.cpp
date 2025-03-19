class Solution {
public:
    string reverseOnlyLetters(string s) {
        int m=s.length();
        int j=m-1;
        int i=0;
        while(i<=j){
            if(isalpha(s[i]) && isalpha(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else{
                if(!isalpha(s[i])){
                    i++;
                }
                else if(!isalpha(s[j])){
                    j--;
                }
            }
        }
        return s;
    }
};