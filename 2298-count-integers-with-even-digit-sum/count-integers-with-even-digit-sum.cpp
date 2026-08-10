class Solution {
public:
    int countEven(int num) {
        int digit=0,n=num;
        while(n){
            digit+=(n%10);
            n/=10;
        }
        return digit%2?(num-1)/2:num/2;
    }
};