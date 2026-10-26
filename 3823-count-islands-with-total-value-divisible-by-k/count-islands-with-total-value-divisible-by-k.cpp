class Solution {
public:
    int m,n;
    long long dfs(vector<vector<int>>& grid,vector<vector<bool>>&visited,int i,int j){
        if(i>=m||i<0||j>=n||j<0||grid[i][j]==0||visited[i][j]) return 0;
        visited[i][j]=true;
        long long sum=grid[i][j];

        sum+=dfs(grid,visited,i,j+1);
        sum+=dfs(grid,visited,i,j-1);
        sum+=dfs(grid,visited,i+1,j);
        sum+=dfs(grid,visited,i-1,j);

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && !visited[i][j]){
                    long long sum=dfs(grid,visited,i,j);
                    if(sum%k==0) cnt++;
                }
            }
        }
        return cnt;
    }
};