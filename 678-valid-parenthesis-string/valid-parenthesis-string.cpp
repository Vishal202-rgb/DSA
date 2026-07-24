class Solution {
public:
    bool check(int idx,int open,string &s,int n,vector<vector<int>>&dp){
        if(idx==n) return open==0;
        if(dp[idx][open]!=-1) return dp[idx][open];

        bool isValid=false;
        if(s[idx]=='*'){
            isValid |=check(idx+1,open+1,s,n,dp);//-->open ke liye
            isValid |=check(idx+1,open,s,n,dp);
            if(open>0){
                isValid |=check(idx+1,open-1,s,n,dp);//-->close ke liye
            }
        }else if(s[idx]=='('){
            isValid |=check(idx+1,open+1,s,n,dp);
        }else if(open>0){
            isValid |=check(idx+1,open-1,s,n,dp);
        }
        return dp[idx][open]=isValid;
    }
    bool checkValidString(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return check(0,0,s,n,dp);
    }
};