class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>lessthanpivot;
        vector<int>equaltopivot;
        vector<int>greaterthanpivot;

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                lessthanpivot.push_back(nums[i]);
            }else if(nums[i]==pivot){
                equaltopivot.push_back(nums[i]);
            }else{
                greaterthanpivot.push_back(nums[i]);
            }
        }
        for(int &num:equaltopivot) lessthanpivot.push_back(num);
        for(int &num:greaterthanpivot) lessthanpivot.push_back(num);
        return lessthanpivot;
    }
};