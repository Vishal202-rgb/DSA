class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        int m=queries.size();
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            int idx=upper_bound(begin(nums),end(nums),queries[i])-begin(nums);
            ans[i]=idx;
        }
        return ans;
    }
};