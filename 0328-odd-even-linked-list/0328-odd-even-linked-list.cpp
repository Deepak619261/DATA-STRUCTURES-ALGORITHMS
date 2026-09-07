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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* secondptr=new ListNode(-1);
        ListNode* dummy =secondptr;
        ListNode* curr=head;
        ListNode* next=head;
        while(curr && curr->next){
            next=curr->next;
            curr->next=next->next;
            secondptr->next=next;
            secondptr=next;
            next->next=NULL;
            curr=curr->next;
        }

        ListNode* temp=head;
        cout<<"printing the first half"<<endl;
        while(temp->next){
            cout<<temp->val<<" ";
            temp=temp->next;
        }

        temp->next=dummy->next;
        return head;
        

        
    }
};