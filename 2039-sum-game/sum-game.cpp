class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftSum = 0, rightSum = 0;
        int leftQnCnt = 0, rightQnCnt = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2)
                    leftQnCnt++;
                else
                    rightQnCnt++;
            } 
            else {
                if (i < n / 2)
                    leftSum += num[i] - '0';
                else
                    rightSum += num[i] - '0';
            }
        }
        int totalQues = leftQnCnt + rightQnCnt;
        if (totalQues % 2 == 1)
            return true;

        if (2 * (leftSum - rightSum) +
            9 * (leftQnCnt - rightQnCnt) == 0)
            return false;

        return true;
    }
};