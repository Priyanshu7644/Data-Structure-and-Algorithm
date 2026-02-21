class Solution {
public:

    // 🔹 Trie Node
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for(int i=0;i<26;i++) child[i]=NULL;
        }
    };

    TrieNode* root = new TrieNode();

    // 🔹 Insert word into Trie
    void insert(string &word){
        TrieNode* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        // ✅ Build Trie
        for(string &w : wordDict)
            insert(w);

        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;

        // ✅ DP + Trie traversal
        for(int i=0;i<n;i++){

            if(!dp[i]) continue;

            TrieNode* node = root;

            for(int j=i;j<n;j++){

                int idx = s[j]-'a';

                if(!node->child[idx]) break;

                node = node->child[idx];

                if(node->isEnd)
                    dp[j+1] = true;
            }
        }

        return dp[n];
    }
};