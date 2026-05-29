class Solution {
public:
    int minElement(vector<int>& nums) {
        int res=INT_MAX;

        for(int num:nums){
            int sum=0;
            while(num){
                sum+=num%10;
                num/=10;
            }
            res=min(res,sum);
        }
        return res;
    }
};