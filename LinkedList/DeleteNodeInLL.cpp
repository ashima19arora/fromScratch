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
  void deleteNode(ListNode* node) {
    while (node->next != nullptr) {
      node->val = node->next->val;
      if (node->next->next != nullptr) {
        node = node->next;
      } else {
        break;
      }
    }
    // you are at second last node
    // you have to delete the last node-all values needed have been shifted
    // last node contains redundant value
    ListNode* toDelete = node->next;
    node->next = nullptr;
    delete toDelete;
  }
};