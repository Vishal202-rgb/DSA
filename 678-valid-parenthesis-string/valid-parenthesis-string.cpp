class Solution {
public:
    // bool check(int idx,int open,string &s,int n,vector<vector<int>>&dp){
    //     if(idx==n) return open==0;
    //     if(dp[idx][open]!=-1) return dp[idx][open];

    //     bool isValid=false;
    //     if(s[idx]=='*'){
    //         isValid |=check(idx+1,open+1,s,n,dp);//-->open ke liye
    //         isValid |=check(idx+1,open,s,n,dp);//-->empty ke liiye 
    //         if(open>0){
    //             isValid |=check(idx+1,open-1,s,n,dp);//-->close ke liye
    //         }
    //     }else if(s[idx]=='('){
    //         isValid |=check(idx+1,open+1,s,n,dp);
    //     }else if(open>0){
    //         isValid |=check(idx+1,open-1,s,n,dp);
    //     }
    //     return dp[idx][open]=isValid;
    // }
    bool checkValidString(string s) {
    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    dp[n][0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            if (s[i] == '*') {
                if (j + 1 <= n)
                    dp[i][j] |= dp[i + 1][j + 1];
                dp[i][j] |= dp[i + 1][j];
                if (j > 0)
                    dp[i][j] |= dp[i + 1][j - 1];
            }
            else if (s[i] == '(') {
                if (j + 1 <= n)
                    dp[i][j] |= dp[i + 1][j + 1];
            }
            else {
                if (j > 0)
                    dp[i][j] |= dp[i + 1][j - 1];
            }
        }
    }
    return dp[0][0];
    }
};