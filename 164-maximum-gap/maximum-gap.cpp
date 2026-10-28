class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        if(n<2) return 0;

        int maximum=INT_MIN;
        for(int i=1;i<n;i++){
            int val=nums[i]-nums[i-1];
            maximum=max(maximum,val);
        }
        return maximum;
    }
};