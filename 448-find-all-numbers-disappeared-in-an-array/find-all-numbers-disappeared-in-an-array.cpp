class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        unordered_map<int,int>mp;

        for(int &num:nums){
            mp[num]++;
        }
        for(int num=1;num<=n;num++){
            if(!mp.count(num)) res.push_back(num);
        }
        return res;
    }
};