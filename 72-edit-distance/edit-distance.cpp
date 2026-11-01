class Solution {
public:
    int solve(int m,int n,string word1, string word2,vector<vector<int>>&dp){
        if(m==0) return n;
        if(n==0) return m;
        if(dp[m][n]!=-1) return dp[m][n];

        if(word1[m-1]==word2[n-1]){
            return dp[m][n]=solve(m-1,n-1,word1,word2,dp);
        }else{
            int insert=1+solve(m,n-1,word1,word2,dp);
            int replace=1+solve(m-1,n-1,word1,word2,dp);
            int dele=1+solve(m-1,n,word1,word2,dp);

            return dp[m][n]=min(insert,min(replace,dele));
        }
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,word1,word2,dp);
    }
};