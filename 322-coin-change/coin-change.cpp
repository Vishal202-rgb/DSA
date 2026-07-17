class Solution {
public:
    int findMinCoin(int n,int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(n==0 || amount<0) return 1e9;
        if(dp[n][amount]!=-1) return dp[n][amount];

        return dp[n][amount]=min(findMinCoin(n-1,amount,coins,dp),1+findMinCoin(n,amount-coins[n-1],coins,dp));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=findMinCoin(n,amount,coins,dp);

        return ans>=1e9 ? -1 : ans;
    }
};