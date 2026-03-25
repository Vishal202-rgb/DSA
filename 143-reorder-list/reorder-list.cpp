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

 //Recursion concept 
class Solution {
public:
    ListNode* curr;
    
    void solve(ListNode* head) {
        if(!head) {
            return;
        }
        
        solve(head->next);
        ListNode* tempn = curr->next;
        if(tempn == NULL) {
            return;
        } else if(head == curr) {
            head->next = NULL;
            return;
        }
        
        curr->next = head;
        head->next = tempn == head ? NULL : tempn;
        
        curr = tempn;
    }
    
    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};