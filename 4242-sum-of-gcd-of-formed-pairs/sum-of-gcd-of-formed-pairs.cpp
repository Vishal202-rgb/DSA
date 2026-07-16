class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        int maxi=INT_MIN;
        vector<long long>prefixGcd(n);

        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            prefixGcd[i] =__gcd(nums[i], maxi);
        }
        int l=0,r=n-1;
        sort(begin(prefixGcd),end(prefixGcd));
        while(l<r){
            res+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return res;
    }
};