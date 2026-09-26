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
  bool chkCycle(ListNode* head) {
    if (head == nullptr or head->next == nullptr) {
      // no cycle in 1 or 0 length ll
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
  ListNode* detectCycle(ListNode* head) {
    if (chkCycle(head) == 0) {
      // no cycle
      return nullptr;
    }
    // find meeting pt
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr and fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        break;
      }
    }
    // now we are at meeting pt
    // to find oc
    fast = head;
    // floyd's algo: dist be head and oc= mieeting pr and oc
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};