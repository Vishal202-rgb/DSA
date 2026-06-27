class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        if(n==0) return 0;

        int currSeq=1,longSeq=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                    currSeq++;
                }else{
                    longSeq=max(longSeq,currSeq);
                    currSeq=1;
                }
            }
        }
        return max(longSeq,currSeq);
    }
};