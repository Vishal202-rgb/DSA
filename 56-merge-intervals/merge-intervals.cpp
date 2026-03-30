class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(begin(intervals),end(intervals));
        vector<vector<int>>res;

        for(auto &interval:intervals){
            if(res.empty()||res.back()[1]<interval[0]){
                res.push_back(interval);
            }else{
                res.back()[1]=max( res.back()[1],interval[1]);
            }
        }
        return res;
    }
};