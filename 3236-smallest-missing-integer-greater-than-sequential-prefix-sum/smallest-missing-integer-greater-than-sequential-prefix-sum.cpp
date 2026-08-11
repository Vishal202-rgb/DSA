class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>fq(begin(nums),end(nums));
        int seq=nums[0];

        for(int j=1;j<n;j++){
            if(nums[j]==nums[j-1]+1){
                seq+=nums[j];
            }else{
                break;
            }
        }
        while(fq.count(seq)){
            seq++;
        }
        return seq;
    }
};