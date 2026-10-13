class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        nth_element(begin(nums),begin(nums)+n/2,end(nums));
        
        long long larger=accumulate(begin(nums)+n/2,end(nums),0LL);
        long long smaller=accumulate(begin(nums),begin(nums)+n/2,0LL);
            return larger-smaller;
    }
};