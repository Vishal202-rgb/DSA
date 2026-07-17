class Solution {
public:
    int findTotalComb(int n,int target,vector<int>&nums,vector<int>&dp){
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(int j=0;j<n;j++){
            ans+=findTotalComb(n,target-nums[j],nums,dp);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return findTotalComb(n,target,nums,dp);
    }
};