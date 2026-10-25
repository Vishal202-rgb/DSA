class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i>=m||i<0||j>=n||j<0||grid[i][j]==0) return;
        grid[i][j]=0;

        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        for(int row=0;row<m;row++){
            //first col 
            if(grid[row][0]==1) dfs(grid,row,0);
            //last col
            if(grid[row][n-1]==1) dfs(grid,row,n-1);
        }
        for(int col=0;col<n-1;col++){
            //first row 
            if(grid[0][col]==1) dfs(grid,0,col);
            //last row
            if(grid[m-1][col]==1) dfs(grid,m-1,col);
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};