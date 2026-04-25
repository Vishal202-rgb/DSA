class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int l = 0, r = 1;
        int len = 0;
        while(n>r) {
            int diff = nums[r] - nums[l];
            if(diff == 1) len = max(len, r - l + 1);
            if(diff <= 1) r++;
            else l++;
        }
        return len;
    }
};