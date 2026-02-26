class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int res=0;

        int i=0,j=n-1;

        while(i<j){
            int sum=nums[i]+nums[j];
            res=max(res,sum);
            i++;
            j--;
        }
        return res;
    }
};