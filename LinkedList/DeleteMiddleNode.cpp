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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr or head->next==nullptr){
            return nullptr;
        }
        //find second midpoint
        ListNode* prev=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr and fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        while(prev->next!=slow){
            prev=prev->next;
        }
        //slow is at midpoint
        //prev is behind slow
        prev->next=slow->next;
        return head;
    }
};