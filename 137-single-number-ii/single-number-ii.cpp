class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;

        for(int k=0;k<32;k++){
            int temp=(1<<k);
            int countZero=0;
            int countOne=0;

            for(int &num:nums){
                if((num&temp)==0){
                    countZero++;
                }else{
                    countOne++;
                }
            }
            if(countOne%3==1) ans=(ans|temp);
        }
        return ans;
    }
};