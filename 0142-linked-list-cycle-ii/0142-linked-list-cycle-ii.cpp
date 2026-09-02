/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast){
                fast=fast->next;
            }
            if(fast==slow){
                break;
            }
        }
        if(fast==NULL)return fast;
        slow=head;
        cout<<fast->val<<endl;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
            if(slow==fast){
                cout<<"matched the node at slow "<<slow->val<<"and fast "<<fast->val<<endl;
            }
        }
        cout<<"reached heere"<<endl;

        return slow;
        
    }
};