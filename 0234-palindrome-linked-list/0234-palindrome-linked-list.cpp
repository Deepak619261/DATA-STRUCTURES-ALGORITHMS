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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        //  first of all reach at the middle 
        //  for even length it will be the one previous 
        // for the odd length it will be the just mid because while comparing we will go via the min length 
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
            if(fast){
                fast=fast->next;
            }
        }

        // ListNode* ptr2=slow;

        if(fast!=NULL){
            prev=slow;
            slow=slow->next;
        }

        prev->next=NULL;
        ListNode* reverseptr=reverse(slow);

        ListNode* first=head;
        ListNode* second=reverseptr;

        while(first && second){
            if(first->val!=second->val){
                ListNode* back=reverse(reverseptr);
                prev->next=back;
                return false;
            }
            first=first->next;
            second=second->next;
        }
         ListNode* back=reverse(reverseptr);
         prev->next=back;
         return true;
        
    }
};