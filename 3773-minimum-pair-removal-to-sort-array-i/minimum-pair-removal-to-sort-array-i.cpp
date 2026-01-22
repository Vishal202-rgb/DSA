class Solution {
public:
int minPairSum(vector<int>& nums){
    int n=nums.size();
    int minSum=INT_MAX;
    int idx=-1;

    for(int i=0;i<n-1;i++){
        if(nums[i]+nums[i+1]<minSum){
            idx=i;
            minSum=nums[i]+nums[i+1];
        }
    }
    return idx;
}
    int minimumPairRemoval(vector<int>& nums) {
        int opn=0;
        while(!is_sorted(begin(nums),end(nums))){
            int idx=minPairSum(nums);

            nums[idx]=nums[idx]+nums[idx+1];
            nums.erase(begin(nums)+idx+1);
            opn++;
        }
        return opn;
    }
};