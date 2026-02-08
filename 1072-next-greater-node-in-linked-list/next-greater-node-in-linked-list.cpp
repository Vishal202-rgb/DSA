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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        int n=ans.size();
        vector<int>nums(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && ans[i]>ans[st.top()]){
                nums[st.top()]=ans[i];
                st.pop();
            }
            st.push(i);
        }
        return nums;
    }
};