class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int idx = 0;
        int n=nums.size();
        sort(begin(nums),end(nums));
        
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[i+1]){
                idx = nums[i];
                break;
            }
        }
        return idx;
    }
};