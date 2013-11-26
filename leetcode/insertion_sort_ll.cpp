/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode* inp = head;
        ListNode* pr_inp = NULL;
        while (inp) {
            ListNode* nx_inp = inp->next;
            
            ListNode* curr = head;
            ListNode* prev = NULL;
            while (curr != inp && curr->val <= inp->val) {
                prev = curr;
                curr = curr->next;
            }
            
            if (curr != inp) {
                // Relink the nodes around inp since inp is moving.
                if (pr_inp) {
                    pr_inp->next = nx_inp;
                }

                // Insert inp in the right place.
                if (prev) {
                    prev->next = inp;
                }
                inp->next = curr;
                if (curr == head) {
                    head = inp;
                }
            } else {
                pr_inp = inp;
            }
            
            inp = nx_inp;
        }
        
        return head;
    }
};