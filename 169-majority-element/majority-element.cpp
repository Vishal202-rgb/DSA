class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        return nums[n/2];
    }
}; 