class Solution {
public:
    int findMaxCherry(int r1,int c1,int r2,int n,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        int c2=(r1+c1)-r2;
        if(r1>=n||r2>=n||c1>=n||c2>=n)
            return INT_MIN;
        if(grid[r1][c1]==-1||grid[r2][c2]==-1)
            return INT_MIN;
        if(r1==n-1&&c1==n-1)
            return grid[n-1][n-1];
        if(dp[r1][c1][r2]!=-1)
            return dp[r1][c1][r2];


        int cherry=grid[r1][c1];
        if(r1!=r2 || c1!=c2)
            cherry+=grid[r2][c2];
        //moving DD,DR,RD,RR
        int DD=findMaxCherry(r1+1,c1,r2+1,n,grid,dp);
        int DR=findMaxCherry(r1+1,c1,r2,n,grid,dp);
        int RD=findMaxCherry(r1,c1+1,r2+1,n,grid,dp);
        int RR=findMaxCherry(r1,c1+1,r2,n,grid,dp);

        int pick=max({DD,DR,RD,RR});
        if(pick==INT_MIN)
            return dp[r1][c1][r2]=INT_MIN;
        
        return dp[r1][c1][r2]=cherry+pick;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans=findMaxCherry(0,0,0,n,grid,dp);
        return max(0,ans);
    }
};