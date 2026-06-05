class Solution {
public:
    int countPrimes(int n) {
        int res=0;
        vector<bool>p(n+1,true);
        p[0]=p[1]=false;

        for(int i=2;i<n;i++){
            if(p[i]){
                res++;
            }
            for(int j=2*i;j<n;j+=i){
                p[j]=0;
            }
        }
        return res;
    }
};