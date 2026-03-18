class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      int prof=0;

      for(int i=1;i<n;i++){
        if(prices[i]>prices[i-1]){
            prof+=prices[i]-prices[i-1];
        }
      }
      return prof;
    }
};