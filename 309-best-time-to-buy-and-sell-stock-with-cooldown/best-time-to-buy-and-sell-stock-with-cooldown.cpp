class Solution {
public:
    int maximumProfit(vector<int>& prices,int idx,int buy,vector<vector<int>>&dp){
        if(idx>=prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int res;

        if(!buy){
            res = max((-prices[idx]+maximumProfit(prices,idx+1,1,dp)),0+maximumProfit(prices,idx+1,0,dp));
        }else{
            res = max((prices[idx]+maximumProfit(prices,idx+2,0,dp)),0+maximumProfit(prices,idx+1,1,dp));
        }
        return dp[idx][buy]=res;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return maximumProfit(prices,0,0,dp);
    }
};