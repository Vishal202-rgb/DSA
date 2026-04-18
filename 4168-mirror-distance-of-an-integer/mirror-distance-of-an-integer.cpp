class Solution {
public:
    int reverse(int n){
        int rem=0;
        while(n>0){
            int d=n%10;
            rem=rem*10+d;
            n/=10;
        }
        return rem;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};