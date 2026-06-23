class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max1 = INT_MIN, max2 = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i]) > max1){
                max2 = max1;
                max1 = abs(nums[i]);
            }else if(abs(nums[i]) > max2){
                 max2 = abs(nums[i]);
            }
        }
        return (long long) max1 * max2 * 1e5;
    }
};