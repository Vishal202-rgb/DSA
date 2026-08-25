class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>prev(2,vector<int>(3,0));

        for(int i=n-1;i>=0;i--){
            vector<vector<int>>curr(2,vector<int>(3,0));
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j==1){
                        curr[j][k]=max(-prices[i]+prev[0][k],prev[1][k]);
                    }else{
                        curr[j][k]=max(prices[i]+prev[1][k-1],prev[0][k]);
                    }
                }
            }
            prev=curr;
        }
        return prev[1][2];
    }
};