class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start < 0 || start >= arr.size()) {
            return false;
        }
        if (arr[start] == 0) {
            return true;
        }
        if (arr[start] < 0) {
            return false;
        }
        
        int jumpLength = arr[start];
        arr[start] = -arr[start]; 
        

        bool jumpForward = canReach(arr, start + jumpLength);
        bool jumpBackward = canReach(arr, start - jumpLength);

        return jumpForward || jumpBackward;
    }
};