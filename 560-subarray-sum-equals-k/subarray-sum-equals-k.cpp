class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;

        int count=0;
        int curSum=0;
         mp[0]=1;
         for(int &x:nums){
            curSum+=x;
            if(mp.find(curSum-k)!=mp.end()){
                count+=mp[curSum-k];
            }
            mp[curSum]++;
         }
         return count;
    }
};