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
  ListNode* oddEvenList(ListNode*& head) {
    // APPROACH 2 - 3 POINTER APPROACH
    if (head == nullptr or head->next == nullptr) {
      // 0 or 1  length ll -do nothing
      return head;
    }
    // make two simultaneous  separate linked list
    // and then merge
    ListNode* oh = head;
    ListNode* eh = head->next;
    ListNode* prev = nullptr;
    ListNode* n = nullptr;
    ListNode*& current = head;
    int jump = 1;

    while (current->next != nullptr) {
      n = current->next;
      current->next = n->next;
      prev = current;
      current = n;
      jump++;
    }
    if (jump % 2 == 0) {
      // even length linked list
      prev->next = eh;
    } else {
      current->next = oh;
    }
    return oh;
  }
};