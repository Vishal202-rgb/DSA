class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=*min_element(begin(nums),end(nums));
        int cnt=0;

        for(int &num:nums){
            cnt+=(num-n);
        }
        return cnt;
    }
};