class Solution {
public:
    int m,n;
    bool dfs(vector<vector<int>>& grid,int row,int col){
        if(row>=m || row<0 || col>=n || col<0) return false;
        if(grid[row][col]==1) return true;
        grid[row][col]=true;

        bool left=dfs(grid,row,col-1);
        bool right=dfs(grid,row,col+1);
        bool up=dfs(grid,row-1,col);
        bool down=dfs(grid,row+1,col);

        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)==true) cnt++;
                }
            }
        }
        return cnt;
    }
};