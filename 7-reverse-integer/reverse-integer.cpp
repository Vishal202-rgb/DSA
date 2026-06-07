class Solution {
public:
    int reverse(int x) {
        long long sum=0;
        while(x!=0){
            int rem=x%10;
            sum=sum*10+rem;
            x/=10;
        }
        if(sum>INT_MAX || sum<INT_MIN){
            return 0;
        }
        return sum;
    }
};