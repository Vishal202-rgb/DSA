class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(int idx, vector<int>& nums) {
        if(idx == n) {
            result.push_back(nums);
            return;
        }
        unordered_set<int> uniqueSet;
        for(int i = idx; i < n; i++) {
            if(uniqueSet.count(nums[i]) > 0) {
                continue;
            }
            uniqueSet.insert(nums[i]);
            swap(nums[i], nums[idx]);
            solve(idx+1, nums);
            swap(nums[i], nums[idx]);    
        }   
    } 
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        solve(0, nums);
        
        return result;
    }
};
