class Solution {
public:
    int findTotalComb(int n,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int ans=0;
        for(int j=0;j<n;j++){
            ans+=findTotalComb(n,target-nums[j],nums,dp);
        }
        return dp[n][target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return findTotalComb(n,target,nums,dp);
    }
};