class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n+1,0);
        int duplicate=0,missing=0;

        for(int i=0;i<n;i++){
            res[nums[i]]++;
        }
        for(int i=1;i<res.size();i++){
            if(res[i]==0) missing=i;
            if(res[i]==2) duplicate=i;
        }
        return {duplicate,missing};
    }
};