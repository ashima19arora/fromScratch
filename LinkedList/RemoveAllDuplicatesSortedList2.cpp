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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MAX, head);
        ListNode* prev = dummy;
        ListNode* current = head;

        while (current != nullptr and current->next != nullptr) {
            if (current->val == current->next->val) {
                int v = current->val;
                while (current != nullptr and current->val == v) {
                    current = current->next;
                }
                prev->next = current;   // prev stays put
            } else {
                prev = current;
                current = current->next;
            }
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};