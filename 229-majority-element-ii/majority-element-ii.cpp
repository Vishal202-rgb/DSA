class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int target = floor(n/3);
        unordered_map<int, int> mp;

        for(int it:nums){
            mp[it]++;
        }
        for(auto it: mp){
            if(it.second > target) ans.push_back(it.first);
        }
        return ans;
    }
};