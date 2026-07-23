class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(begin(intervals),end(intervals));
        int i=0,j=1,cnt=0;

        while(j<n){
            vector<int>curr=intervals[i];
            vector<int>next=intervals[j];

            int cs=curr[0];
            int ce=curr[1];
            int ns=next[0];
            int ne=next[1];

            if(ce<=ns){
                i=j;
                j++;
            }else if(ce<=ne){
                j++;
                cnt++;
            }else if(ce>ne){
                i=j;
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};