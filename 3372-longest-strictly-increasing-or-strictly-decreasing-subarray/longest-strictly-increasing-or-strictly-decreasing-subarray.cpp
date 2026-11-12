class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int incr=1,decr=1,res=1;

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                incr++;
                decr=1;
                res=max(res,incr);
            }else if(nums[i]<nums[i-1]){
                decr++;
                incr=1;
                res=max(res,decr);
            }else{
                incr=1;
                decr=1;
            }
        }
        return res;
    }
};