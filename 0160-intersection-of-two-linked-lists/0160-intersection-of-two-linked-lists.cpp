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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int>mpp;
        ListNode* temp=headA;

        while(temp){
            mpp[temp]++;
            temp=temp->next;
        }

        temp=headB;

        while(temp){
            if(mpp[temp]!=0){
                return temp;
            }
            temp=temp->next;
        }


        return NULL;
    }
};