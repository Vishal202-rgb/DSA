class Solution {
public:
    int findMaxPathSum(int r1,int c1,int r2,int c2,int row,int col,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>>&dp){
        
        if(r1<0||r2<0||c1<0||c2<0||c1>=col||c2>=col)
            return INT_MIN;
        if(r1==row-1){
            if(c1!=c2){
                return grid[r1][c1]+grid[r2][c2];
            }
            else{
                return grid[r1][c1];
            }
        }
        if(dp[r1][c1][c2][0]!=-1)
            return dp[r1][c1][c2][0];
        int cherry=grid[r1][c1];
        if(c1!=c2)
            cherry+=grid[r2][c2];

        int LL = findMaxPathSum(r1+1,c1-1,r2+1,c2-1,row,col,grid,dp);
        int LR = findMaxPathSum(r1+1,c1-1,r2+1,c2+1,row,col,grid,dp);
        int LS = findMaxPathSum(r1+1,c1-1,r2+1,c2,row,col,grid,dp);
        int SL = findMaxPathSum(r1+1,c1,r2+1,c2-1,row,col,grid,dp);
        int SS = findMaxPathSum(r1+1,c1,r2+1,c2,row,col,grid,dp);
        int SR = findMaxPathSum(r1+1,c1,r2+1,c2+1,row,col,grid,dp);
        int RL = findMaxPathSum(r1+1,c1+1,r2+1,c2-1,row,col,grid,dp);
        int RS = findMaxPathSum(r1+1,c1+1,r2+1,c2,row,col,grid,dp);
        int RR = findMaxPathSum(r1+1,c1+1,r2+1,c2+1,row,col,grid,dp);

        int pick=max({LL,LR,LS,SL,SS,SR,RL,RS,RR});
        if(pick==INT_MIN)
            return dp[r1][c1][c2][0]= INT_MIN;

        return dp[r1][c1][c2][0]=cherry+pick;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<vector<int>>>>dp(m,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(1,-1))));
        int ans=findMaxPathSum(0,0,0,n-1,m,n,grid,dp);
        return max(0,ans);
    }
};