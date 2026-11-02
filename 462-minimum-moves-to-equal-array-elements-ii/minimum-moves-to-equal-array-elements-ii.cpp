class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int moves=0;
        nth_element(begin(nums),begin(nums)+n/2,end(nums));
        int mid=nums[n/2];

        for(int i=0;i<n/2;i++){
            moves+=abs(nums[i]-mid);
            moves+=abs(nums[n-i-1]-mid);

        }
        return moves;
    }
};