class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head != nullptr) {
            ans = (ans << 1) | head->val;
            head = head->next;
        }
        return ans;
    }
};