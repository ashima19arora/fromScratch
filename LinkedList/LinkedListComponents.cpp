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
  int numComponents(ListNode*& head, vector<int>& nums) {
    // given nums is a subset of the linkedlist values
    // connected component-maximal sequence of consecutive nodes s.t every
    // node's value belongs to nums
    ListNode* temp = head;
    if (head == nullptr) {
      return 0;
    }
    // creating freq array for nums
    int freq[10001]{0};
    for (int i = 0; i < nums.size(); i++) {
      int number = nums[i];
      freq[number]++;
    }
    int component = 0;
    while (temp != nullptr) {
      if (freq[temp->val] == 1) {
        component++;
        if (temp->next == nullptr) {
          // we have reached end
          return component;
        } else {
          temp = temp->next;
        }
        while (freq[temp->val] == 1) {
          if (temp->next == nullptr) {
            // we have reached end
            return component;
          } else {
            temp = temp->next;
          }
        }
      } else {
        // not  in nums
        if (temp->next == nullptr) {
          // we have reached end
          return component;
        } else {
          temp = temp->next;
        }
      }
    }
    return component;
  }
};