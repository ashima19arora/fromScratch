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
  bool hasCycle(ListNode* head) {
    // using floyd's algo:
    // if a ll has cycle then two pointers moving at proportional speed are
    // bound to meet if not fast will reach end
    if (head == nullptr or head->next == nullptr) {
      return false;
    }
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr and fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        return true;
      }
    }
    return false;
  }
};