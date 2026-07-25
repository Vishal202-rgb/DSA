class Solution {
public:
    int maxProduct(int n) {
        vector<int>res;

        while(n>0){
            int num=n%10;
            res.push_back(num);
            n/=10;
        }
        sort(begin(res),end(res));
        return res[res.size()-1]*res[res.size()-2];
    }
};