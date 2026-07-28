class Solution {
public:
    int minStep(int m,int n,string &word1, string &word2,vector<vector<int>>&dp){
        if(m==0) return n;
        if(n==0) return m;
        if(dp[m][n]!=-1) return dp[m][n];

        if(word1[m-1]==word2[n-1]){
            return dp[m][n]= minStep(m-1,n-1,word1,word2,dp);
        }else{
            int del=1+minStep(m-1,n,word1,word2,dp);
            int insert=1+minStep(m,n-1,word1,word2,dp);
            int replace=1+minStep(m-1,n-1,word1,word2,dp);

            return dp[m][n]= min(del,min(insert,replace));
        }
    }
    int minDistance(string word1, string word2) {
       int m=word1.size(),n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       return minStep(m,n,word1,word2,dp); 
    }
};