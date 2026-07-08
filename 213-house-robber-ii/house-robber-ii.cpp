class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

       vector<int>dp(3,0);
       dp[1]=nums[0];
       dp[2]=max(nums[0],nums[1]);

       for(int i=2;i<n-1;i++){
       dp[0]=dp[1];
       dp[1]=dp[2];
       dp[2]=max(nums[i]+dp[0],dp[1]);
       }
       int ans=dp[2];

       dp[1]=nums[1];
       dp[2]=max(nums[1],nums[2]);

       for(int i=3;i<n;i++){
       dp[0]=dp[1];
       dp[1]=dp[2];
       dp[2]=max(nums[i]+dp[0],dp[1]);
       }
       ans=max(ans,dp[2]);
       return ans;
    }
};