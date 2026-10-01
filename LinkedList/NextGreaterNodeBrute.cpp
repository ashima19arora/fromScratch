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
  vector<int> nextLargerNodes(ListNode* head) {
    // optimized
    ListNode* current = head;
    ListNode* agla = nullptr;
    vector<int> ans;
    int i = 1;
    while (current->next != nullptr) {
      agla = current->next;
      int flag = 0;
      while (agla->val <= current->val) {
        if (agla->next == nullptr) {
          flag = 1;
          break;
        }
        agla = agla->next;
      }
      // either u found greater node or u reached end linked list
      if (flag == 1) {
        // ans[i]=0;
        ans.push_back(0);
      } else {
        // found greater node
        //  ans[i]=agla->val;
        ans.push_back(agla->val);
      }
      current = current->next;
      i++;
    }
    // u r at last node
    ans.push_back(0);
    return ans;
  }
};