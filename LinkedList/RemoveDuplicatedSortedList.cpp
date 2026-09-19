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
  ListNode* deleteDuplicates(ListNode*& head) {
    if (head == nullptr or head->next == nullptr) {
      return head;
    }
    ListNode* prev = head;
    ListNode* agla = nullptr;
    while (prev != nullptr and
           prev->next != nullptr) {  // second last node ke liye we ll check
      agla = prev->next;
      // check if value match-duplicate
      if (prev->val == agla->val) {
        // look for  next distinct node
        while (agla->next != nullptr and agla->val == agla->next->val) {
          agla = agla->next;
        }
        // distict node  or agla->next=null
        prev->next = agla->next;
      }

      prev = prev->next;
    }
    return head;
  }
};