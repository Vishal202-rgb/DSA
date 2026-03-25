class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<ll>rowSum(m,0);
        vector<ll>colSum(n,0);
        ll totalSum=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                totalSum+=grid[i][j];
                //row
                rowSum[i]+=grid[i][j];
                //col
                colSum[j]+=grid[i][j];
            }
        }
        if(totalSum%2!=0) return false;
        //horizontal breaking
        ll upper=0;
        for(int i=0;i<m-1;i++){
            upper+=rowSum[i];
            if(upper==totalSum-upper){
                return true;
            }
        }
        //vertical breaking
         ll left=0;
        for(int j=0;j<n-1;j++){
            left+=colSum[j];
            if(left==totalSum-left){
                return true;
            }
        }
        return false;
    }
};