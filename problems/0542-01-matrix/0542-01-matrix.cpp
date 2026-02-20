class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();          
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));

        queue<tuple<int,int,int>> q;  
        // push all zero cells
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){      
                if(mat[r][c]==0){
                    q.push(make_tuple(r,c,0));
                    ans[r][c]=0;
                }
            }
        }
        //trick 
        vector<int> direction = {-1,0,1,0,-1};

        while(!q.empty()){          
            auto [r,c,dist] = q.front();   
            q.pop();

            for(int d=0; d<4; d++){
                int nr = r + direction[d];
                int nc = c + direction[d+1];

                if(nr>=0 && nc>=0 && nr<n && nc<m && ans[nr][nc]==-1){
                    ans[nr][nc] = dist + 1;
                    q.push({nr,nc,dist+1});
                }
            }
        }

        return ans;
    }
};