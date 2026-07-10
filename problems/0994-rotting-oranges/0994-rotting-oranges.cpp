class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        int ans=0;

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
            q.pop();
            ans=max(t,ans);

            if(i-1>=0 && grid[i-1][j]==1 && !vis[i-1][j]){
                q.push({{i-1,j},t+1});
                grid[i-1][j]=2;
                vis[i-1][j]=1;
            }

            if (j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] == 1) {
                q.push({{i, j + 1}, t + 1});
                vis[i][j + 1] = 1;
                grid[i][j + 1] = 2;
            }

            if (i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] == 1) {
                q.push({{i + 1, j}, t + 1});
                vis[i + 1][j] = 1;
                grid[i + 1][j] = 2;
            }

            if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1) {
                q.push({{i, j - 1}, t + 1});
                vis[i][j - 1] = 1;
                grid[i][j - 1] = 2;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
};