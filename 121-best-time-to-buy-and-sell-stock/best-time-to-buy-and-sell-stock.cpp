class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0,mn=prices[0];
        for(int i=0;i<n;i++){
            mn=min(mn,prices[i]);
            int profit=prices[i]-mn;
            ans=max(ans,profit);
        }
        return ans;
    }
};