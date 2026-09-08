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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 
        if(head->next==NULL && n==1)return NULL; 
        ListNode* slow=head;
        ListNode* fast=head;
        int count=0;
        while(count<n && fast){
            fast=fast->next;
            count++;
        }
        if(fast==NULL){
            ListNode* ans=head->next;
            head->next=NULL;
            return ans;
        }

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
        
    }
};