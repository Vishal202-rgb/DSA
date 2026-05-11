class Solution {
public:
    int minimumSum(int num) {
        vector<int>ans;
        int s1=0,s2=0;

        while(num>0){
            int a=num%10;
            ans.push_back(a);
            num/=10;
        }
        sort(begin(ans),end(ans));
        s1=ans[0]*10+ans[3];
        s2=ans[1]*10+ans[2];

        return s1+s2;
    }
};