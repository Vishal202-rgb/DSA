class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int small=INT_MAX;
        int large=INT_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++){
            small=min(nums[i],small);
            large=max(nums[i],large);
        }
        if(large-small-2*k<=0||n==1){
            return 0;
        }else{
            return (large-small-2*k);
        }
    }
};