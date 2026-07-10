class Solution {
public:
    int count=0;
    void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || grid[i][j]!=1){
            return;
        }
        vis[i][j]=1;
        count++;
        dfs(grid,vis,i-1,j,n,m);
        dfs(grid,vis,i+1,j,n,m);
        dfs(grid,vis,i,j-1,n,m);
        dfs(grid,vis,i,j+1,n,m);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && (grid[i][j]==1 && !vis[i][j])){
                    
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }

        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    total++;
                }
            }
        }
        return total-count;
    }
};