class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        int fractionnum = maxi;
        int smallestnum = mini;
        while(fractionnum%smallestnum!=0){
            int temp = fractionnum%smallestnum;
            fractionnum =smallestnum;
            smallestnum=temp;
        }
        return smallestnum;
    }
};