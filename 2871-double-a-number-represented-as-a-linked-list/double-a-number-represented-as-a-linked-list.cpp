class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL) {
            
            int newVal = curr->val * 2;
            
            if(newVal < 10) {
                curr->val = newVal;
            } else if(prev != NULL) {
                curr->val = newVal%10;
                
                prev->val += 1;
            } else { //prev is NULL means we are standing at head node
                ListNode* newHead = new ListNode(1);
                newHead->next = curr;
                curr->val = newVal%10;
                head = newHead;
            }
            prev = curr;
            curr = curr->next;   
        }
        return head;
    }
};