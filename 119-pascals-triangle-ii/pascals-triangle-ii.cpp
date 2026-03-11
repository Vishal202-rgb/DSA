class Solution {
public:
    vector<int> getRow(int n) {
        vector<int>res(n,1);

        for(int i=0;i<n+1;i++){
            vector<int>temp(n+1,1);

            for(int j=1;j<i;j++){
                temp[j]=res[j-1]+res[j];
            }
            res=temp;
        }
        return res;
    }
};