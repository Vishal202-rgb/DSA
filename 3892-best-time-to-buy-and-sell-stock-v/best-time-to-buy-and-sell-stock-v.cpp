class Solution {
public:
    long long maxProfit(int index, int buy, int transaction, int n, vector<int>&prices,vector<vector<vector<long long>>>&dp){  
      if(transaction == 0)  return 0;
      if(index==n) return buy == 1? INT_MIN: 0;

      if(dp[index][buy][transaction]!=-1)
      return dp[index][buy][transaction];
       
       if(buy==2){
          // ya toh mein nahi purchase karunga, ya mein buy karunga, pa mein short sellin wala buy karunga

        return dp[index][buy][transaction] = max(maxProfit(index+1,2,transaction,n,prices,dp), max( -prices[index]+maxProfit(index+1,0,transaction, n, prices,dp), prices[index]+ maxProfit(index+1,1,transaction,n, prices,dp)));
       }
       else if(buy==1){
        // short selling : short sell karoge ya nahi karoge
         
         return dp[index][buy][transaction] = max(-prices[index]+maxProfit(index+1,2,transaction-1,n,prices,dp), maxProfit(index+1,1,transaction,n,prices,dp));
       }
       else{
        // normal selling: sell kar do aaj, ya na karo

        return dp[index][buy][transaction]= max(prices[index]+maxProfit(index+1,2,transaction-1,n,prices,dp), maxProfit(index+1,0,transaction,n,prices,dp));
       }
     }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>>dp(n+1, vector<vector<long long>>(3,vector<long long>(k+1,-1)));

        return maxProfit(0,2,k,n,prices,dp);
    }
};