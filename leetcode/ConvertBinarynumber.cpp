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
  int getDecimalValue(ListNode*& head) {
    if (head == nullptr) {
      return 0;
    }
    // traverse to get length
    ListNode* temp = head;
    int count = 0;
    while (temp != nullptr) {
      count++;
      temp = temp->next;
    }
    int index = count - 1;
    // convert to decimal
    temp = head;
    int decimalval = 0;
    while (temp != nullptr) {
      decimalval += temp->val * pow(2, index);
      index--;
      temp = temp->next;
    }
    return decimalval;
  }
};