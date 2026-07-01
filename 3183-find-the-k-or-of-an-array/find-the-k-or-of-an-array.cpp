class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int sum=0;

        for(int i=0;i<32;i++){
            int cnt=0;
            for(int &x:nums){
                if(x&(1<<i)) cnt++;
            }
            if(cnt>=k) sum|=(1<<i);
        }
        return sum;
    }
};