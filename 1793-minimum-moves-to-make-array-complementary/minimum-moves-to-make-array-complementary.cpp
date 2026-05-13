class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>diff(2*limit+2);

        for(int i=0;i<n/2;i++){

            int a = nums[i];
            int b = nums[n-i-1];

            if(a > b) swap(a,b);

            int sum = a+b;
            int left = a+1;
            int right = b+limit;

            // Assume 2 moves for all sums
            diff[2] += 2;
            diff[2*limit+1] -= 2;

            // 1 move range
            diff[left] -= 1;
            diff[right+1] += 1;

            // 0 move point
            diff[sum] -= 1;
            diff[sum+1] += 1;
        }
        int res = INT_MAX;
        int curr = 0;
        for(int s=2;s<=2*limit;s++){
            curr += diff[s];
            res = min(res,curr);
        }
        return res;
    }
};