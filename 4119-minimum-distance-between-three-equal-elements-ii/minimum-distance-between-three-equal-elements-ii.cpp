class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<int> pp = nums;

        unordered_map<int, vector<int>> indices;
        int n = pp.size();
        int ans = INT_MAX;
        bool found = false;
        for (int i = 0; i < n; i++) {
            indices[pp[i]].push_back(i);
        }
        for (auto &p : indices) {
            auto &v = p.second;
            if (v.size() >= 3) {
                for (int i = 0; i + 2 < v.size(); i++) {
                    int a = v[i], b = v[i+1], c = v[i+2];
                    int dist = abs(a - b) + abs(b - c) + abs(c - a);
                    ans = min(ans, dist);
                    found = true;
                }
            }
        }

        return found ? ans : -1;
    }
};