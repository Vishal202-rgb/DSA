class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        if(k>numOnes){
            ans += numOnes;
            k -= numOnes;
        }else{
            return k;
        }
        k -= numZeros;
        if(k<=0)
        return ans;

        ans += (k*(-1));
        return ans;
    }
};