class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>res;
        int num=0;
        
        for(int i=0;i<n;i++){
            num=(num*2+nums[i])%5;
            res.push_back(num==0);
        }
        return res;
    }
};