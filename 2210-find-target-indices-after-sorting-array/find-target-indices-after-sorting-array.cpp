class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
     int n=nums.size();
     vector<int>ans;
     sort(begin(nums),end(nums));

     for(int i=0;i<n;i++){
        if(nums[i]==target) ans.push_back(i);
     }   
     return ans;
    }
};