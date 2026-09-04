class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            int maxEl=INT_MIN;
            int minEl=INT_MAX;
            for(int j=0;j<=i;j++){
                maxEl=max(maxEl,nums[j]);
            }
            for(int j=i;j<=n-1;j++){
                minEl=min(minEl,nums[j]);
            }
            if(maxEl-minEl<=k) return i;
        }
        return -1;
    }
};