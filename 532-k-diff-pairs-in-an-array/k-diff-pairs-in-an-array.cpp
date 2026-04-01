class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        set<pair<int,int>>res;

        int i=0,j=1;
        while(i<n&&j<n){
            if(i!=j &&(nums[j]-nums[i]==k)){
                res.insert({nums[i],nums[j]});
                i++,j++;
            }else if(nums[j]-nums[i]<k){
                j++;
            }else{
                i++;
            }
            if(i==j) j++;
        }
        return res.size();
    }
};