class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=s.size();
        int l=0;
        int ans=0;
        vector<int>freq(266,0);
        for(int r=0;r<size;r++){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};