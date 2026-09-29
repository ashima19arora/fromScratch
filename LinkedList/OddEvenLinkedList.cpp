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
    if (head == nullptr or head->next == nullptr) {
      // 0 or 1 or 2 length ll -do nothing
      return head;
    }
    // make two simultaneous  separate linked list
    // and then merge
    ListNode* oh = nullptr;
    ListNode* ot = nullptr;
    ListNode* eh = nullptr;
    ListNode* et = nullptr;
    while (head != nullptr) {
      // odd linked list addittion
      if (oh == nullptr) {
        oh = ot = head;
      } else {
        ot->next = head;
        ot = head;
      }
      head = head->next;  // saving reference of next node
      ot->next = nullptr;

      // even linked list addtion
      // odd lenght linked list-//head would be already at null
      if (head != nullptr) {
        if (eh == nullptr) {
          eh = et = head;
        } else {
          et->next = head;
          et = head;
        }
        head = head->next;  // saving reference of next node
        et->next = nullptr;
      }
    }
    ot->next = eh;
    return oh;
  }
};