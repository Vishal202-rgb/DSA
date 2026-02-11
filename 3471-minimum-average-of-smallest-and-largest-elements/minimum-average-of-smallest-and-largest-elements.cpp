class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        deque<int>dq(nums.begin(), nums.end());
        double ans= 1e18;

        while (!dq.empty()) {
            double avg = (dq.front() + dq.back()) / 2.0;
            ans = min(ans, avg);
            dq.pop_front();
            dq.pop_back();
        }
        return ans;
    }
};