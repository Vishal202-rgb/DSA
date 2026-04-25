class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int rightSum = 0;
        for (int i = 0; i < n; i++) rightSum += nums[i];

        vector<int> ans(n, 0);
        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        return ans;
    }
};