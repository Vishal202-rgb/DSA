class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int>ans;
        int s1=0,s2=0;

        while(n>0){
            int a=n%10;
            ans.push_back(a);
            n/=10;
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(i%2==0){
                s1+=ans[i];
            }else{
                s2+=ans[i];
            }
        }
        int sum=s1-s2;
        return sum;
    }
};