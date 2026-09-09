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
        if(head->next==NULL || head==NULL)return NULL;
        ListNode* slow=head;
        ListNode* slowprev=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slowprev=slow;
            slow=slow->next;
            fast=fast->next;
            if(fast)fast=fast->next;
        }

        slowprev->next=slow->next;
        slow->next=NULL;
        return head;
        
    }
};