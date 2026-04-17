class Solution {
public:
    int reverse(int n){
        int rev=0;

        while(n>0){
            int rem=n%10;
            rev=rev*10+rem;
            n/=10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int res=INT_MAX;

        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                res=min(res,i-mp[nums[i]]);
            }
            mp[reverse(nums[i])]=i;
        }
        return res==INT_MAX?-1:res;
    }
};