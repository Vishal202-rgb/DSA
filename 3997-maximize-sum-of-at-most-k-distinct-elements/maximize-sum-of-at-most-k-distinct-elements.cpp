class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(begin(nums),end(nums),greater<>());
        vector<int>res;
        int i=1;
        res.push_back(nums[0]);
        while(k>1){
            if(nums[i]!=nums[i-1]){
                res.push_back(nums[i]);
                k--;
            }
            if(i==nums.size()-1) break;
            i++;
        }
        return res;
    }
};