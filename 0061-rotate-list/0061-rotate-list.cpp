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
    int getlen(ListNode* head){
        if(head==NULL) return 0;

        int len=0;

        ListNode* temp=head;

        while(temp){
            len++;
            temp=temp->next;
        }

        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        int len=getlen(head);


       

        if(head==NULL || head->next==NULL || k==0 || k==len) return head;
        

        ListNode* slow=head;
        ListNode* fast=head;
        

        while(k>len){
            k=k%len;
        }

        if(k==len || k==0) return head;
       

    

        int cnt=0;

        while(cnt<k && fast->next){
            fast=fast->next;
            cnt++;
        }

        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }

        ListNode*ans=slow->next;
        slow->next=NULL;

        fast->next=head;

        return ans;
    }
};