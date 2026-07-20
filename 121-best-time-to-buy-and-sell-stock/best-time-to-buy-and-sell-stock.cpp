class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),bestBuy=prices[0],profit=0;

        for(int i=1;i<n;i++){
            if(prices[i]>bestBuy){
                profit=max(profit,prices[i]-bestBuy);
            }else{
                bestBuy=prices[i];
            }
        }
        return profit;
    }
};