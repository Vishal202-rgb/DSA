class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n=prices.size();
        if(n==1) return money;
        sort(begin(prices),end(prices));
        
        if((prices[0] + prices[1]) > money)
            return money;
        else
            return money -(prices[0] + prices[1]);
    }
};