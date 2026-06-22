class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int>res;
        int tar=floor(n/3);

        for(auto &it:nums)
        mp[it]++;

        for(auto &it:mp){
            if(it.second>tar) res.push_back(it.first);
        }
        return res;
    }
};