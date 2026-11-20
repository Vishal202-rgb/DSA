class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto lembdaP=[](int num){
            return num>0;
        };
        auto lembdaN=[](int num){
            return num<0;
        };
        int pos=count_if(begin(nums),end(nums),lembdaP);
        int neg=count_if(begin(nums),end(nums),lembdaN);
        return max(pos,neg);
    }
};