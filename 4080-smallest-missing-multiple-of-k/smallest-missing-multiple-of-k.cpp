class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>mp;

        for(auto &num:nums){
            mp.insert(num);
        }
        int val=k;
        while(mp.count(val)){
            val+=k;
        }
        return val;
    }
};