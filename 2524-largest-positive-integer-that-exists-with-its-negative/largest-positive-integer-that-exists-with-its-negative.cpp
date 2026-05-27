class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int i=0,j=nums.size()-1;

        while(i<j){
            if(nums[j]==-nums[i]) return nums[j];
            else if(nums[j]<-nums[i]) i++;
            else j--;
        }
        return -1;
    }
};