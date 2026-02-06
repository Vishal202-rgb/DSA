class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int L=1;
        int maxE1=nums[0];
        int minE1=nums[0];
        int i=0;
        int j=0;

        while(j<n){
            int minE1=nums[i];
            int maxE1=nums[j];
             while(maxE1>(long long)k*minE1){
            i++;
            minE1=nums[i];
        }
        L=max(L,j-i+1);
        j++;
        } 
        return n-L;
    }
};