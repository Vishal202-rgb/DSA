class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        //normalization
        k=k%n;
        if(k==0) return;

        auto reverse=[&](int i,int j){
            while(i<j){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        };
        reverse(0,n-1);
        reverse(0,k-1);
        reverse(k,n-1);
    }
};