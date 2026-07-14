class Solution {
public:
    bool findSubset(int n,int tar,vector<int>& nums,vector<vector<int>>&dp){
        if(tar==0) return true;
        if(n==0 || tar<0) return false;
        if(dp[n][tar]!=-1) return dp[n][tar];

        return dp[n][tar]=findSubset(n-1,tar,nums,dp)+findSubset(n-1,tar-nums[n-1],nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tar=0;
        for(auto &x:nums){
            tar+=x;
        }
        if(tar%2!=0) return false;
        vector<vector<int>>dp(n+1,vector<int>(tar/2+1,-1));
        return findSubset(n,tar/2,nums,dp);
    }
};