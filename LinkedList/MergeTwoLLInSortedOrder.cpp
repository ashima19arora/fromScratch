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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* t1 = list1;
    ListNode* agla1 = nullptr;
    ListNode* t2 = list2;
    ListNode* agla2 = nullptr;
    ListNode* list3 = new ListNode(INT_MIN);
    ListNode* t3 = list3;
    while (t1 != nullptr and t2 != nullptr) {
      if (t1->val < t2->val) {
        agla1 = t1->next;
        t3->next = t1;
        t3 = t1;
        t1 = agla1;
      } else {
        agla2 = t2->next;
        t3->next = t2;
        t3 = t2;
        t2 = agla2;
      }
    }
    while (t2 != nullptr) {
      t3->next = t2;
      t3 = t3->next;
      t2 = t2->next;
    }
    while (t1 != nullptr) {
      t3->next = t1;
      t3 = t3->next;
      t1 = t1->next;
    }
    return list3->next;
  }
};