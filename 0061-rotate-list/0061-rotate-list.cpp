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
    ListNode* rotateRight(ListNode* head, int k) {
        //  edge case
        if(head==NULL || head->next==NULL || k==0) return head;

        int len=1;

        ListNode* temp=head;

        while(temp->next){
            len++;
            temp=temp->next;
        }

        temp->next=head;
        k=k%len;
        k=len-k-1;

        temp=head;

        while(k>0){
            temp=temp->next;
            k--;
        }

        ListNode* ans=temp->next;

        temp->next=NULL;

        return ans;


    }
};