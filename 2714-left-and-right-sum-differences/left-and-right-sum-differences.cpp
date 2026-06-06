class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int rytSum=0;

        for(int i=0;i<n;i++){
            rytSum+=nums[i];
        }
        vector<int>res(n,0);
        int lftSum=0;
        for(int i=0;i<n;i++){
            rytSum-=nums[i];
            res[i]=abs(lftSum-rytSum);
            lftSum+=nums[i];
        }
        return res;
    }
};