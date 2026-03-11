class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int i, vector<int>& temp) {
        //base case
        if(i >= nums.size()) {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);//tske 0th element
        solve(nums, i+1, temp);
        temp.pop_back();//not take 0th element
        solve(nums, i+1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);

        return result;
    }
};