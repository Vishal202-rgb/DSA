class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(1,nums[0]);

        for(int i=1;i<n;i++){
            int idx=lower_bound(begin(ans),end(ans),nums[i])-begin(ans);

            if(idx==ans.size()){
                ans.push_back(nums[i]);
            }else if(nums[i]<ans[idx]){
                ans[idx]=nums[i];
            }
        }
        return ans.size();
    }
};