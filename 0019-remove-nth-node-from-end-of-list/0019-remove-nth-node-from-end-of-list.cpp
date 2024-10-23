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
        // for you sunshine ! 
     ListNode* first=head;   
     ListNode* second=head;

    //   the approach is very simple , we have to keep a distance of N between these two pointer and get to the last of the linked automatically the first pointer will be pointing towards the Nth from the last 
    int count=n;

    while(count){
        second=second->next;
        count--;
    }
    
    while(second && second->next){
        second=second->next;
        first=first->next;
    }

    if(second==NULL) return first->next;

    if(first->next){
        first->next=first->next->next;
    }

    return head;

    }
};