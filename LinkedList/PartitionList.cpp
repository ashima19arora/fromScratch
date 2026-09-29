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
  ListNode* partition(ListNode*& head, int x) {
    if (head == nullptr or head->next == nullptr) {
      // ll of lenght 0 or 1
      return head;
    }
    // we will have our original list and from that we will try to create
    // two simultaneous lists one having values smaller than given x and one
    // having values equal or greater
    ListNode* ch = nullptr;
    ListNode* ct = nullptr;  // to traverse 1st linked list
    ListNode* bh = nullptr;
    ListNode* bt = nullptr;  // to traverse the second linked list

    // now for each node  decide wether they would become part of small ll
    // or  big
    while (head != nullptr) {
      if (head->val < x) {
        // belongs to small ll
        // insert it in
        // first time insertion
        if (ch == nullptr) {
          ch = ct = head;
        } else {
          ct->next = head;
          ct = head;
        }
        // ct is on last node of the list rn
        // preserve the reference of next node in org LL bbefore
        // poitning ct to null
        head = head->next;
        ct->next = nullptr;
      } else {
        // belongs to big ll
        // insert it in
        // first time insertion
        if (bh == nullptr) {
          bh = bt = head;
        } else {
          bt->next = head;
          bt = head;
        }
        // bt is on last node of the list rn
        // preserve the reference of next node in org before LL poitning
        // bt to null
        head = head->next;
        bt->next = nullptr;
      }
    }
    // what if all values are less than x->only one ll
    if (ch == nullptr) {
      return bh;
    }
    // now we have two linked list, join them
    ct->next = bh;
    // return reference of first node of small
    return ch;
  }
};