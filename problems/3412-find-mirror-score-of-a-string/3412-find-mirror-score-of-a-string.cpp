class Solution {
public:
    long long calculateScore(string s) {
        vector<vector<int>>pos(26);
        long long score=0;
        for(int i=0;i<s.size();i++){
            char mirror=('a'+'z')-s[i];
            if(!pos[mirror-'a'].empty()){
                int j=pos[mirror-'a'].back();
                pos[mirror-'a'].pop_back();
                score+=(i-j);
            }
            else{
                pos[s[i]-'a'].push_back(i);
            }
        }
        return score;
    }
};