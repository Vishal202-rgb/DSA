class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int>mp=nums;

        int n=nums.size();
        int res=0;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(mp[j]==target) cnt++;

                int l=j-i+1;
                if(cnt*2>l)
                res++;
            }
        }
        return res;
    }
};