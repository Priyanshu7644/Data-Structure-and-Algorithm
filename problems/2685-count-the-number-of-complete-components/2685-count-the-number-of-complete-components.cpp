class Solution {
public:

    void solve(vector<vector<int>>&adj,int start,vector<int>&visited,int &node,int &edge){
        visited[start]=1;
        node++;
        edge+=adj[start].size();
        for(auto it:adj[start]){
            if(!visited[it]){
                solve(adj,it,visited,node,edge);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>visited(n,0);
        int count=0;
        for(int j=0;j<n;j++){
            if(!visited[j]){
                int node=0;
                int edge=0;
                solve(adj,j,visited,node,edge);
                edge=edge/2;
                if(edge==((node)*(node-1))/2){
                    count++;
                }
            }
        }
        return count;
    }
};