class Solution {
public:
    int n;
    int check(vector<int>& stoneValue,int i,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

       int res=stoneValue[i]-check(stoneValue,i+1,dp);
       if(i+1<n)
            res=max(res,stoneValue[i]+stoneValue[i+1]-check(stoneValue,i+2,dp));
        if(i+2<n)
            res=max(res,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-check(stoneValue,i+3,dp));

        return dp[i]=res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        vector<int>dp(n,-1);
        int diff=check(stoneValue,0,dp);

        if(diff>0)
            return "Alice";
        else if(diff<0)
            return "Bob";

        return "Tie";
    }
};