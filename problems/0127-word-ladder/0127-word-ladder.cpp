class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string curr=q.front().first;
            int level=q.front().second;
            q.pop();
            if(curr==endWord){
                return level;
            }
            for(int i=0;i<curr.size();i++){
                char ch=curr[i];
                for(char j='a';j<='z';j++){
                    curr[i]=j;
                    if(st.find(curr)!=st.end()){
                        q.push({curr,level+1});
                        st.erase(curr);
                    }
                    curr[i]=ch;
                }
            }
        }
        return 0;
    }
};