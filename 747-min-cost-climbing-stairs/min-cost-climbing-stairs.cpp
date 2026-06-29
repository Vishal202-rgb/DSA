class Solution {
public:
    int t[1001];
    int check(int idx,vector<int>& cost){
        if(idx>=cost.size()) return 0;
        if(t[idx]!=-1) return t[idx];

        int a=cost[idx]+check(idx+1,cost);
        int b=cost[idx]+check(idx+2,cost);
        return t[idx]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(t,-1,sizeof(t));
        return min(check(0,cost),check(1,cost));
    }
};