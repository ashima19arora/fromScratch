// reversing part of linked list

// way 1 iteratively
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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // trivial cases
    if (head == nullptr or left == right) {
      return head;
    }
    // move prev to one node behind left
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    for (int i = 1; i < left; i++) {
      prev = prev->next;
    }

    // move current to left node
    ListNode* current = prev->next;

    // implement 3 pointer approach
    ListNode* sectionStart = current;
    ListNode* sectionPrev = nullptr;
    ListNode* sectionAgla = nullptr;

    // reverse the nodes left-right+1 times
    for (int i = 1; i <= right - left + 1; i++) {
      sectionAgla = sectionStart->next;
      sectionStart->next = sectionPrev;
      sectionPrev = sectionStart;
      sectionStart = sectionAgla;
    }

    // connect the desired nodes
    current->next = sectionStart;
    prev->next = sectionPrev;
    return dummy->next;
  }
};

// way 2 recursively
class Solution {
 public:
  void F(ListNode* end, ListNode*& start, bool& stop, int left, int right) {
    // we will check if we are at desired position first before we swap
    if (right == 1) {
      return;
    }
    // that means we are not at desired position
    // increment start and end as per
    end = end->next;
    if (left > 1) {
      start = start->next;
    }

    // now check again if we are at right position
    F(end, start, stop, left - 1, right - 1);
    // u r right postion now , now swap if required
    if (start == end or end->next == start) {
      stop = true;
    }
    if (!stop) {
      swap(start->val, end->val);
      start = start->next;
    }
    return;
  }
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // trivial cases
    if (head == nullptr or left == right) {
      return head;
    }
    ListNode* start = head;
    ListNode* end = head;
    bool stop = false;
    F(end, start, stop, left, right);
    return head;
  }
};