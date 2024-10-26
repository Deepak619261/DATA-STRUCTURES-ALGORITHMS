/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getlen(ListNode* head){
        if(head==NULL) return 0;

        int len=1;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }

        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff=getlen(headA)-getlen(headB);

        if(diff>0){
            while(diff){
                headA=headA->next;
                diff--;
            }
        }
        else if(diff<0){
            while(diff!=0){
                headB=headB->next;
                diff++;
            }
        }


        while(headB){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }

        return NULL;
    }
};