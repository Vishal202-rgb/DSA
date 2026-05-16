class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_map<int,int>mp;
        sort(begin(ranges),end(ranges));

        for(auto &it:ranges){
            if(it[0]<=left && it[1]>=right) return true;
            else if(it[0]<=left && it[1]<=right) left=max(it[1]+1,left);
        }
        return false;
    }
};