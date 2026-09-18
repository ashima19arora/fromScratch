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
  ListNode* splitLL(ListNode* head) {
    if (head == nullptr or head->next == nullptr) {
      return head;
    }
    // 2 pointer approach to find the middle point
    // we will find the first middle point
    ListNode* fast = head->next;
    ListNode* slow = head;
    while (fast != nullptr and fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    // slow is at 1st midpoint
    // make the split
    ListNode* agla = slow->next;
    slow->next = nullptr;
    return agla;
  }
  ListNode* reverseLLRecursively(ListNode* head) {
    if (head == nullptr or head->next == nullptr) {
      return head;
    }
    ListNode* reverseHead = reverseLLRecursively(head->next);
    head->next->next = head;
    head->next = nullptr;
    return reverseHead;
  }
  void reorderList(ListNode*& head) {
    if (head->next == nullptr or head->next->next == nullptr) {
      // 1 length ll
      return;
    }
    // first task is to split the linked list
    ListNode* head2 = splitLL(head);
    // now reverse the second linked list
    ListNode* reversedHead = reverseLLRecursively(head2);
    // now we have two linked list- head, reversedhead
    ListNode* temp = head;
    ListNode* agla1 = nullptr;
    ListNode* agla2 = nullptr;
    while (reversedHead != nullptr and head != nullptr) {
      agla1 = head->next;
      head->next = reversedHead;
      agla2 = reversedHead->next;
      reversedHead->next = agla1;
      head = agla1;
      reversedHead = agla2;
    }
    head = temp;
  }
};