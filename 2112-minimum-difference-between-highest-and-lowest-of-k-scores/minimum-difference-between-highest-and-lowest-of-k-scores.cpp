class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0;
        sort(begin(nums),end(nums));
        int ans=INT_MAX;

        for(int i=0;i+k-1<nums.size();i++){
            int diff=nums[i+k-1]-nums[i];
            ans=min(ans,diff);
        }
        return ans;
    }
};