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
   ListNode* reverseList(ListNode* head){
    if(head==NULL|| head->next==NULL) return head;

    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* next=curr->next;

    while(curr){
        curr->next=prev;
        prev=curr;
        curr=next;
        
        if(curr) next=curr->next;
    }

    return prev;
   }

   ListNode* getKthnode(ListNode* head, int k){
    ListNode* temp=head;
    int cnt=1;

    while(cnt!=k && temp){
        temp=temp->next;
        cnt++;
    }

    return temp;
   }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    

        ListNode* temp=head;
        ListNode* prevlast=NULL;

        while(temp!=NULL){

            ListNode* kthNode=getKthnode(temp,k);

            if(kthNode==NULL){
                if(prevlast){
                    prevlast->next=temp;
                }
                break;
            }


            ListNode* next=kthNode->next;
            kthNode->next=NULL;

            reverseList(temp);

            if(temp==head){
                head=kthNode;
            }
            else{
                prevlast->next=kthNode;
            }

            prevlast=temp;

            temp=next;
           
        }

        return head;

    }
};