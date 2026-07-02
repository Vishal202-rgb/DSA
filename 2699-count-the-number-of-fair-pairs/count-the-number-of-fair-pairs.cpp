class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        long long res=0;
        for(int i=0;i<n;i++){
            int lwr=lower-nums[i];
            int upr=upper-nums[i];

            res+=upper_bound(begin(nums)+(i+1),end(nums),upr)-lower_bound(begin(nums)+(i+1),end(nums),lwr);
        }
        return res;
    }
};