class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int maximum=0,minimum=1001;

        for(int i=0;i<n;i++){
            if(nums[i]<minimum){
                minimum=nums[i];
            }if(nums[i]>maximum){
                maximum=nums[i];
            }
        }
        return __gcd(minimum,maximum);
    }
};