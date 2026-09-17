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
    // two pointer approach - give second midpoint in even ll
    if (head == nullptr or head->next == nullptr) {
      return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr and fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode*& midPoint = slow;
    ListNode* prev = head;
    while (prev->next != slow) {
      prev = prev->next;
    }
    prev->next = nullptr;
    return midPoint;
  }

  ListNode* reverseLLiteratively(ListNode* head) {
    // 3 pointer approach
    if (head == nullptr or head->next == nullptr) {
      return head;
    }
    ListNode* current = head;
    ListNode* prev = nullptr;
    ListNode* agla = nullptr;
    while (current != nullptr) {
      agla = current->next;
      current->next = prev;
      prev = current;
      current = agla;
    }
    return prev;
  }

  bool isPalindrome(ListNode* head) {  // pass by reference
    if (head->next == nullptr) {
      return true;
    }
    // split linked list in two halves and we will check if they r same
    // after reverseing the second half
    ListNode* head2 = splitLL(head);
    ListNode* reversehead2 = reverseLLiteratively(head2);
    while (head != nullptr) {
      if (head->val != reversehead2->val) {
        return false;
        break;
      }
      head = head->next;
      reversehead2 = reversehead2->next;
    }
    return true;
  }
};