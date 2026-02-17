class Solution {
public:
    int findMin(vector<int>& nums) {
        // int n=nums.size();
        // sort(begin(nums),end(nums));
        // vector<int>ans;
        
        // for(int i=0;i<n;i++){
        //     if(nums[i]<nums[j] && )
        // }

        return *min_element(nums.begin(), nums.end());
    }
};