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
     ListNode* reverseList(ListNode* head) {

        if(head==NULL) return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=curr->next;


        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=next;
            if(curr)    next=curr->next;
        }

        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }


        ListNode* second=reverseList(slow->next);

        ListNode* temp=head;

        while(second){
            if(temp->val != second->val)  return false;
            temp=temp->next;
            second=second->next;
        }

        reverseList(slow->next);

        return true;
        
    }
};