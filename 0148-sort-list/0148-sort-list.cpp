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
    ListNode* merge(ListNode* list1, ListNode* list2){
        
        // make a dummy node 
        ListNode* dummy =new ListNode(-1);
        ListNode* temp=dummy;

        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }


            temp=temp->next;

        }

        if(list2){
            temp->next=list2;
        }

        if(list1){
            temp->next=list1;
        }


        temp=dummy->next;

        dummy->next=NULL;
        delete(dummy);

        return temp;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        //  recursive approach 
        if(head==NULL || head->next==NULL){
            return head;
        }

        //  get the middle element by slow and fast algorithm 
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* middle=slow->next;
        slow->next=NULL;
        ListNode* lefthalf=sortList(head);
        ListNode* righthalf=sortList(middle);

        return merge(lefthalf,righthalf);
    }
};