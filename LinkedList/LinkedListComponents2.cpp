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
  int numComponents(ListNode* head, vector<int>& nums) {
    // given nums is a subset of the linkedlist values
    // connected component-maximal sequence of consecutive nodes s.t every
    // node's value belongs to nums
    if (head == nullptr) {
      return 0;
    }
    // creating freq array for nums
    int freq[10001]{0};
    for (int i = 0; i < nums.size(); i++) {
      freq[nums[i]]++;
    }
    int component = 0;
    while (head != nullptr) {
      if ((freq[head->val] == 1) and
          (head->next == nullptr or freq[head->next->val] == 0)) {
        // current val is in nums and (either next node is null or next node val
        // not in nums)
        component++;
      }
      head = head->next;
    }
    return component;
  }
};