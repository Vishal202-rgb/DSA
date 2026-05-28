class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[1] > b[1];
            });

        int ans = 0;
        for (auto &box : boxTypes) {

            int boxes = min(truckSize, box[0]);

            ans += boxes * box[1];

            truckSize -= boxes;

            if (truckSize == 0)
                break;
        }
        return ans;
    }
};