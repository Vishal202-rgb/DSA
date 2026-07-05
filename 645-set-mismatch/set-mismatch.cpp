class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n+1);
        int dup=0,miss=0;

        for(int i=0;i<n;i++){
            ans[nums[i]]++;
        }
        for(int i=1;i<ans.size();i++){
            if(ans[i]==0) miss=i;
            if(ans[i]==2) dup=i;
        }
        return {dup,miss};
    }
};