class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int res=0;
        mp[0]=-1;

        for(int i=0;i<n;i++){
            res+=nums[i];
            int rem=res%k;

            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2)
                    return true;
            }else{
                    mp[rem]=i;   
            }
        }
        return false;
    }
};