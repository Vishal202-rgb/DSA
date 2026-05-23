class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int total=0;

        for(int &x:nums){
            if(total<0) total=0;
            total+=x;
            ans=max(ans,total);
        } 
        return ans;
    }
};