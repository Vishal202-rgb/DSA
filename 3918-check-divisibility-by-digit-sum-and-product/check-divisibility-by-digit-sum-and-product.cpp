class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n,sum=0,prod=1;

        while(temp>0){
            int digit=temp%10;
            sum+=digit;
            prod*=digit;

            temp/=10;
        }
        return n%(sum+prod)==0;
    }
};