class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        int cumS=0;
        for(int i=0;i<n;i++){
            int ls=cumS;
            int rs=sum-cumS-nums[i];

            if(ls==rs) return i;
            cumS+=nums[i];
        }
        return -1;
    }
};