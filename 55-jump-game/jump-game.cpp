class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxm=0;

        for(int i=0;i<n;i++){
            if(i>maxm) return false;
            maxm=max(maxm,i+nums[i]);
        }
        return true;
    }
};