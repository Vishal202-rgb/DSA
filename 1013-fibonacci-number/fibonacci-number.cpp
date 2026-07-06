class Solution {
public:
    int fibnoacci(int n,vector<int>&dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];

        return dp[n]=fibnoacci(n-1,dp)+fibnoacci(n-2,dp);
    }
    int fib(int n) {
        //Approach-1 (Recursion)
        /*if(n<=1) return n;
         return fib(n-1)+fib(n-2);*/

         //Approach-02 (Top-Down Approach)
         /*vector<int>dp(n+1,-1);
         return fibnoacci(n,dp);*/

         //Approach-03 (Bottom-Up Approach)
         if(n<=1) return n;
         vector<int>dp(n+1);

         dp[0]=0;
         dp[1]=1;

         for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
         }
         return dp[n];
    }
};