class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end());
        unordered_map<int, int> preSum;
        set<int> hasAction;
        int preSer = -1, preMaxRange = 0, maxVal = -1;
        for(int i=0;i<logs.size();i++) {
            int server = logs[i][0];
            int time = logs[i][1];
            if(server==preSer) {
                if(time > (preMaxRange+x)) {
                    preSum[preMaxRange+x+1] += -1;
                    preSum[time] += 1;
                    hasAction.insert(time);
                    hasAction.insert(preMaxRange+x+1);
                }
                preMaxRange = time;
            } else {
                if(preSer != -1) {
                    preSum[preMaxRange + x + 1] += -1;
                    hasAction.insert(preMaxRange+x+1);
                }
                preMaxRange = time;
                preSum[time] += 1;
                preSer = server;
                hasAction.insert(time);
            }
        }
        preSum[preMaxRange + x + 1] += -1;
        hasAction.insert(preMaxRange+x+1);
        unordered_map<int, bool> isInQuery;
        unordered_map<int, int> result;
        for(int i=0;i<queries.size();i++) {
            isInQuery[queries[i]] = true;
            maxVal = max(maxVal, queries[i]);
            hasAction.insert(queries[i]);
        }
        int sum = 0;
        for(int i:hasAction) {
            sum += preSum[i];
            if(isInQuery[i]) {
                result[i] = sum;
            }
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++) {
            ans.push_back(n-result[queries[i]]);
        }
        return ans;
    }
};