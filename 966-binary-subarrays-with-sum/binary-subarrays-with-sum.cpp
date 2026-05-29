class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int cnt=0,currsum=0;
        mp[0]=1;

        for(int &num:nums){
            currsum+=num;
            if(mp.find(currsum-goal)!=mp.end()){
                cnt+=mp[currsum-goal];
            }
            mp[currsum]++;
        }
        return cnt;
    }
};