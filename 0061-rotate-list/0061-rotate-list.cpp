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
    int GetLength(ListNode* head){
        ListNode* temp=head;
        int count=0;

        while(temp){
            temp=temp->next;
            count++;
        }

        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || head->next==NULL)return head;


        ListNode* temp=head;

        // cout<<GetLength(head)<<endl;
        int len=GetLength(head);

        k=k%len;

        if(k==0)return head;

        int lenact=len-k-1;

        ListNode* lastptr=head;

        while(lastptr->next){
            lastptr=lastptr->next;
        }
        
        while(lenact--){
            head=head->next;
        }

        ListNode* newhead=head->next;

        head->next=NULL;
        lastptr->next=temp;


        return newhead;
    }
};