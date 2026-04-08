/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> res;
        ListNode* ptr = head;
        while (ptr != NULL) {
            res.push_back(ptr->val);
            ptr = ptr->next;
        }
        sort(begin(res),end(res));
        ptr = head;
        int i = 0;
        while (ptr != NULL) {
            ptr->val = res[i];
            i++;
            ptr = ptr->next;
        }
        return head;
    }
};