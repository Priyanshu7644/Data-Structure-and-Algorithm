class Solution {
public:

    void dfs(vector<vector<int>>adj,int start,vector<int>&visited){
        visited[start]=1;
        for(auto it:adj[start]){
            if(!visited[it]){
                dfs(adj,it,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int>visited(n,0);
        int count=0;
        for(int k=0;k<n;k++){
            if(!visited[k]){
                dfs(adj,k,visited);
                count++;
            }
        }
        return count;
    }
};