class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        unordered_map<int,int>mp;
        int res=0;

        for(auto &it:nums){
            mp[it+1]=max(mp[it+1],mp[it]+1);
            mp[it]=max(mp[it],mp[it-1]+1);

            res=max({res,mp[it],mp[it+1]});
        }
        return res;
    }
};