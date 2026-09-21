class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>ans(k),dp(k);

        for(int x:nums){
            vector<long long>curr(k);
            int r=x%k;

            curr[r]++;
            for(int j=0;j<k;j++)
                curr[j*r%k]+=dp[j];

            for(int j=0;j<k;j++)
                ans[j]+=curr[j];
            
            dp=curr;
        }
        return ans;
    }
};