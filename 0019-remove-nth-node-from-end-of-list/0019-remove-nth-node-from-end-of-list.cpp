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
        int count =0;

        ListNode* temp=head;

        while(temp){
            count++;
            temp=temp->next;
        }

        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //  doing with two pass first 
        int len=getlen(head);

        if(n>len) return head;

        // if(head->next==NULL && n==1) return NULL;

        

        int del_ind=len-n+1;

        ListNode* temp=head;

        int counter=0;
        ListNode* prev=NULL;

        while(temp){
            counter++;
            
            if(counter==del_ind){
                if(prev==NULL){
                    return temp->next;
                }else{
                     prev->next=temp->next;
                     break;
                }
            }

            prev=temp;
            temp=temp->next;
        }

        return head;
    }
};