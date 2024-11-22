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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy =new ListNode(-1);
        ListNode* temp=dummy;
        dummy->next=head;

        if(head==NULL || head->next==NULL) return head;

        while(temp->next && temp->next->next){
            ListNode* first=temp->next;
            ListNode* second=temp->next->next;
            
            first->next=second->next;
            second->next=first;
            temp->next=second;

            temp=first;
        }

        return dummy->next;
    }
};