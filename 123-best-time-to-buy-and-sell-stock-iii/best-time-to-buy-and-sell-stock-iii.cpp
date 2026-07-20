class Solution {
public:
    int maximumProfit(int idx,int buy,int transiction,int n,vector<int>& prices,vector<vector<vector<int>>>&dp){
        if(transiction==0 || idx==n) return 0;
        if(dp[idx][buy][transiction]!=-1) return dp[idx][buy][transiction];
        if(buy){
            //either i can buy the stock and i will not buy the stock
            return dp[idx][buy][transiction]=max((-prices[idx]+maximumProfit(idx+1,0,transiction,n,prices,dp)),maximumProfit(idx+1,1,transiction,n,prices,dp));
        }else{
            //either i cal sell the stock today or i can't sell the stock today
            return dp[idx][buy][transiction]=max((prices[idx]+maximumProfit(idx+1,1,transiction-1,n,prices,dp)),maximumProfit(idx+1,0,transiction,n,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return maximumProfit(0,1,2,n,prices,dp);
    }
};