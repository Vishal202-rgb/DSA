class Solution {
public:
    int minMoves(vector<int>& nums) {
        int val=*max_element(begin(nums),end(nums));
        int moves=0;

        for(int &num:nums){
            moves+=val-num;
        }
        return moves;
    }
};