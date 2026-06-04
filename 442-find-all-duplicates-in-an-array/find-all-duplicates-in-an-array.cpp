class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>mp;

        for(int &num:nums){
            mp[num]++;
            if(mp[num]==2) res.push_back(num);
        }
        return res;
    }
};