class Solution {
public:
    int m,n;
    int t[71][71][71];
    int solve(vector<vector<int>>& grid,int row,int c1,int c2){
        if(row>=m) return 0;
        if(t[row][c1][c2]!=-1){
            return t[row][c1][c2];
        }
        int cherry=grid[row][c1];
        if(c1!=c2){
            cherry+=grid[row][c2];
        }
        int res=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int newR=row+1;
                int newC1=c1+i;
                int newC2=c2+j;

                if(newC1>=0 && newC1<n && newC2>=0 && newC2<n)
                res=max(res,solve(grid,newR,newC1,newC2));
            }
        }
        return t[row][c1][c2]=cherry+res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(grid,0,0,n-1);
    }
};