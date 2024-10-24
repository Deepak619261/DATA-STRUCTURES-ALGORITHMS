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
        if(head==NULL) return NULL;

        ListNode* first=new ListNode(-1);
        ListNode* second=new ListNode(-1);
        ListNode* firstcurr=first;
        ListNode* secondcurr=second;

        ListNode* temp=head;
        int cnt=1;

        while(temp){
            if(cnt%2==0){
              secondcurr->next=temp;
              temp=temp->next;
              secondcurr=secondcurr->next;
              secondcurr->next=NULL;
            }
            else{
                firstcurr->next=temp;
                temp=temp->next;
                firstcurr=firstcurr->next;
                firstcurr->next=NULL;
            }
            cnt++;
        }

        firstcurr->next=second->next;
        return first->next;

    }
};