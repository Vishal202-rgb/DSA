class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int minprice=INT_MAX;

        for(auto &x:items){
            minprice=min(minprice,x[1]);
        }
        const int maxf=1500;
        vector<int>freq(maxf+1,0);
        for(auto &x:items){
            freq[x[0]]++;
        }
        vector<int>multiplescnt(maxf+1,0);
        for(int f=1;f<=maxf;f++){
            for(int m=f;m<=maxf;m+=f){
                multiplescnt[f]+=freq[m];
            }
        }
        vector<int>value(n);
        for(int i=0;i<n;i++){
            int factor=items[i][0];
            int free=multiplescnt[factor]-1;
            value[i]=1+free;
        }
        vector<int>dp(budget+1,-1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int cost=items[i][1];
            for(int b=budget;b>=cost;b--){
                dp[b]=max(dp[b],dp[b-cost]+value[i]);
            }
        }
        int res=0;
        for(int cost=0;cost<=budget;cost++){
            if(dp[cost]<0) continue;
            int rem=budget-cost;

            res=max(res,dp[cost]+rem/minprice);
        }
        return res;
    }
};