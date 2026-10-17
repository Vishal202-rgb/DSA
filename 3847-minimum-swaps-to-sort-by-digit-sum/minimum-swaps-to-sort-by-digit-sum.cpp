class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>>mp;

        for (int i = 0; i < n; i++) {
            mp.push_back({nums[i], i});
        }

        sort(mp.begin(), mp.end(),[&](const auto& a, const auto& b) {
            int sumA = digitSum(a.first);
            int sumB = digitSum(b.first);

            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a.first < b.first;
        });
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || mp[i].second == i) {
                continue;
            }
            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = mp[j].second;
                cycleSize++;
            }
            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }
        return swaps;
    }
};