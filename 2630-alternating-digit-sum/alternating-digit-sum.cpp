class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> ans;
        int sum1=0;
        int sum2=0;
        while(n>0){
            int fd=n%10;
            ans.push_back(fd);
            n=n/10;
        }
        reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++){
            if(i%2==0){
                sum1+=ans[i];
            }
            else{
                sum2+=ans[i];
            }
        }
        int sum=sum1-sum2;
    return sum;
    }
};