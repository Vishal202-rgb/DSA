class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        int cnt=0;

        for(int i=0;i<n;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                cnt=1;
            }else{
                cnt++;
            }
            if(cnt<=k) res.push_back(nums[i]);
        }
        return res;
    }
};