class Solution {
public:    
    int countEven(int num) {
        int ans =num;
        int sum=0;
        while(ans>0){
            sum+=ans%10;
            ans/=10;
        }
    if(sum%2==0){
        return num/2;
    }
    return (num-1)/2 ;
    }
};