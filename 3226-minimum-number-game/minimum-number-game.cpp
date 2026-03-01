class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        sort(begin(nums),end(nums));

        for(int i=1;i<n;i+=2){
            ans.push_back(nums[i]);
            ans.push_back(nums[i-1]);
        }
        return ans;
    }
};