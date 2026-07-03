class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        sort(begin(nums),end(nums));

        for(int i=n-1;i>=2;i--){
            int low=0,high=i-1;

            while(low<high){
                if(nums[low]+nums[high]>nums[i]){
                    res+=(high-low);
                    high--;
                }else{
                    low++;
                }
            }
        }
        return res;
    }
};