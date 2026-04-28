class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        nth_element(begin(nums),begin(nums)+n/2,end(nums));//sorting only for the mid element
        int mid=nums[n/2];

        for(int i=0;i<n;i++){
            cnt+=abs(nums[i]-mid);
        }
        return cnt;
    }
};