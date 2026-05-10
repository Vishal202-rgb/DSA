class Solution {
public:
    int n;
    int solve(int i,vector<int>&nums,int target,vector<int>&t){
        if(i==n-1) return t[i]=0;
        if(t[i]!=INT_MIN){
            return t[i];
        }
        int ans=INT_MIN;
        for(int j=i+1;j<n;j++){
            if(abs(nums[i]-nums[j])<=target){
                int temp=1+solve(j,nums,target,t);
                ans=max(ans,temp);
            }
        }
        return t[i]=ans;

    }
    int maximumJumps(vector<int>& nums, int target) {
        n=nums.size();
        vector<int>t(n+1,INT_MIN);
        int ans=solve(0,nums,target,t);

        return ans<0 ? -1 : ans;
    }
};