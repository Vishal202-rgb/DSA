class Solution {
public:
     vector<vector<int>>res;
     void solve(int i,vector<int>& nums,vector<int>& temp){
        if(i>=nums.size()){
            res.push_back(temp);
            return;
        }
        //take 0th element
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
        
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        solve(idx,nums,temp);
     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int>temp;
        solve(0,nums,temp);

        return res;
    }
};