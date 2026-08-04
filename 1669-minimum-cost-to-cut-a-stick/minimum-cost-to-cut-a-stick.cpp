class Solution {
public:
    int findMinCost(int st,int end,vector<int>&cuts,vector<vector<int>>&dp){
        if(st+1==end) return 0;

        if(dp[st][end]!=-1) return dp[st][end];
        int res=INT_MAX;

        for(int k=st+1;k<end;k++){
            int ans=cuts[end]-cuts[st]+findMinCost(st,k,cuts,dp)+findMinCost(k,end,cuts,dp);
            res=min(res,ans);
        }
        return dp[st][end]= res;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts),end(cuts));

        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return findMinCost(0,cuts.size()-1,cuts,dp);
    }
};