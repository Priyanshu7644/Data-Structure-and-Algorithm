class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int oldcolor,int color,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || image[i][j]!=oldcolor){
            return;
        }
        image[i][j]=color;
        dfs(image,i-1,j,oldcolor,color,n,m);
        dfs(image,i+1,j,oldcolor,color,n,m);
        dfs(image,i,j-1,oldcolor,color,n,m);
        dfs(image,i,j+1,oldcolor,color,n,m);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int color) {
        int n=image.size();
        int m=image[0].size();
        int oldcolor=image[i][j];
        if(color==oldcolor){
            return image;
        }
        dfs(image,i,j,oldcolor,color,n,m);

        return image;
    }
};