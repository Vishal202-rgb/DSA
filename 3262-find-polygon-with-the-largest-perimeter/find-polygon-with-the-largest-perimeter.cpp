class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        long long sum=0;
        long long ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<sum){
                ans=nums[i]+sum;
            }
            sum+=nums[i];
        }
        return ans;
    }
};